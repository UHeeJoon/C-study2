#include<bits/stdc++.h>
using namespace std;
bool house[18][18];
int n, cnt;
void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {1,2}, 1 });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int way = q.front().second;
		if (y == n && x == n)cnt++;
		q.pop();
		if (way == 1) {
			if (x + 1 <= n && !house[y][x + 1]) {
				q.push({ {y, x + 1}, 1 });
			}
			if (y + 1 <= n && x + 1 <= n && !house[y + 1][x + 1] && !house[y + 1][x] && !house[y][x + 1]) {
				q.push({ {y + 1, x + 1}, 3 });
			}
		}
		if (way == 2) {
			if (y + 1 <= n && !house[y + 1][x]) {
				q.push({ {y + 1,x}, 2 });
			}
			if (y + 1 <= n && x + 1 <= n && !house[y + 1][x + 1] && !house[y + 1][x] && !house[y][x + 1]) {
				q.push({ {y + 1, x + 1}, 3 });
			}
		}
		if (way == 3) {
			if (x + 1 <= n && !house[y][x + 1]) {
				q.push({ {y, x + 1}, 1 });
			}
			if (y + 1 <= n && !house[y + 1][x]) {
				q.push({ {y + 1, x}, 2 });
			}
			if (y + 1 <= n && x + 1 <= n && !house[y + 1][x + 1] && !house[y + 1][x] && !house[y][x + 1]) {
				q.push({ {y + 1, x + 1}, 3 });
			}
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> house[i][j];
	house[1][1] = house[1][2] = 1;
	bfs();
	cout << cnt << '\n';
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
bool _map[17][17];
int dr[3] = {0,1,1};
int dc[3] = {1,0,1};
int answer= 0;

//범위 체크 and 벽 체크
bool chk(int r, int c){
	if (r < 1 || r > N || c < 1 || c > N || _map[r][c]) return false;
	else return true;
}

void DFS(int r, int c, int dir){

	if(r==N && c==N){
		answer++;
		return;
	}

	for(int i = 0; i<3; i++){
		//가로->세로 or 세로->가로 안됨
		if((dir==0 && i==1) || (dir==1 && i==0)) continue;

		int nr = r + dr[i];
		int nc = c + dc[i];
		if(chk(nr,nc)==false) continue;     //범위 벗어나거나 벽이면
		if(i==2 && (_map[r+1][c] || _map[r][c+1])) continue;    //대각선인데 나머지 칸이 벽이면
		DFS(nr, nc, i);

	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> _map[i][j];
	DFS(1,2, 0);
	cout << answer << '\n';
	return 0;
}
*/