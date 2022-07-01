#include<bits/stdc++.h>
using namespace std;
int n = 0, m = 0;
char arr[12][12];

int r_y, r_x;
int b_y, b_x;
int result = 0;

int y_ar[4] = { 0,0,1,-1 };
int x_ar[4] = { 1, -1, 0, 0 };
bool visited[12][12][12][12] = { 0, };

int bfs() {
	queue <pair <int, int>> b_que;
	queue <pair <int, int>> r_que;
	b_que.push(make_pair(b_y, b_x));
	r_que.push(make_pair(r_y, r_x));
	result = 0; // 0으로 초기화
	while (!b_que.empty()) {
		int sized = (int)b_que.size();
		while (sized--) {
			int red_y = r_que.front().first;
			int red_x = r_que.front().second;
			int blue_y = b_que.front().first;
			int blue_x = b_que.front().second;
			r_que.pop(), b_que.pop();
			if (arr[red_y][red_x] == 'O') // O에 있을때
				return result;
			for (int i = 0; i < 4; i++) {
				int nextred_y = red_y;
				int nextred_x = red_x;
				int nextblue_y = blue_y;
				int nextblue_x = blue_x;
				while (arr[nextred_y + y_ar[i]][nextred_x + x_ar[i]] != '#' && arr[nextred_y][nextred_x] != 'O') {
					nextred_y += y_ar[i];
					nextred_x += x_ar[i];
				}
				while (arr[nextblue_y + y_ar[i]][nextblue_x + x_ar[i]] != '#' && arr[nextblue_y][nextblue_x] != 'O') {
					nextblue_y += y_ar[i];
					nextblue_x += x_ar[i];
				}
				if (nextred_y == nextblue_y && nextred_x == nextblue_x) {
					if (arr[nextred_y][nextred_x] == 'O') continue; // 이 경로는 가면 안되는 경로라서 continue로 넘겨줌 	
					// 더 많이 이동한쪽이 진짜 자기 위치  
					if ((abs(nextred_y - red_y) + abs(nextred_x - red_x)) > (abs(nextblue_y - blue_y) + abs(nextblue_x - blue_x)))
						nextred_y -= y_ar[i], nextred_x -= x_ar[i];
					else
						nextblue_y -= y_ar[i], nextblue_x -= x_ar[i];
				}
				if (visited[nextred_y][nextred_x][nextblue_y][nextblue_x]) continue; //기존에 방문했다면 
				r_que.push(make_pair(nextred_y, nextred_x));
				b_que.push(make_pair(nextblue_y, nextblue_x));
				visited[nextred_y][nextred_x][nextblue_y][nextblue_x] = 1;
			}
		}
		if (result == 10) return -1;
		result++;
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B')
				b_y = i, b_x = j, arr[i][j] = '.';
			else if (arr[i][j] == 'R')
				r_y = i, r_x = j, arr[i][j] = '.';
		}
	}
	cout << bfs() << '\n';
	return 0;
}