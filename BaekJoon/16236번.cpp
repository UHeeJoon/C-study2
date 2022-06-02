#include<bits/stdc++.h>
using namespace std;
#define MAX 22
int space[MAX][MAX];
int n;
int dy[] = { 1,0,-1,0 }, dx[] = { 0,-1,0,1 };
int visited[MAX][MAX];
struct Fish {
	int y, x, value;
};
int x, y;
int mag = 2, bite = 0, cnt = 0;
vector<Fish>vec;
bool comp(const Fish& a, const Fish& b) {
	if (a.value == b.value) {
		if (a.y == b.y)
			return a.x < b.x;
		return a.y < b.y;
	}
	return a.value < b.value;
}
int BFS(int a, int b) {
	vec.clear();
	fill(&visited[0][0], &visited[0][0] + 22 * 22, -1);
	queue<pair<int, int>> q;
	visited[a][b] = 0;
	q.push({ a,b });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + cur.first;
			int nx = dx[i] + cur.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (visited[ny][nx] > -1 || space[ny][nx] > mag)continue;
			if (space[ny][nx] > 0 && space[ny][nx] < mag) {
				Fish fish;
				fish.y = ny; fish.x = nx;
				fish.value = visited[cur.first][cur.second] + 1;
				vec.push_back(fish);
			}
			q.push({ ny, nx });
			visited[ny][nx] = visited[cur.first][cur.second] + 1;
		}
	}
	if (!vec.empty()) {
		sort(vec.begin(), vec.end(), comp);
		auto N = vec[0];
		y = N.y, x = N.x;
		cnt += N.value;
		space[y][x] = 0;
		bite++;
		if (bite == mag) {
			bite = 0;
			mag++;
		}
		return 1;
	}
	else return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				y = i;
				x = j;
			}
		}
	}
	space[y][x] = 0;
	while (1) {
		if (!BFS(y, x))break;
	}
	cout << cnt << '\n';
	return 0;
}