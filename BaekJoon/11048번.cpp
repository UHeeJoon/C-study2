#include<bits/stdc++.h>
using namespace std;
int _map[1001][1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> _map[i][j];
	for (int i = 2; i <= m; i++)
		_map[1][i] = _map[1][i - 1] + _map[1][i];
	for (int i = 2; i <= n; i++)
		_map[i][1] = _map[i - 1][1] + _map[i][1];
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++)
			_map[i][j] = max(_map[i][j - 1], _map[i - 1][j]) + _map[i][j];
	cout << _map[n][m] << '\n';
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int _map[1001][1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> _map[i][j];
			if (i == 1)
				_map[i][j] = _map[i][j - 1] + _map[i][j];
			else if (j == 1)
				_map[i][j] = _map[i-1][j] + _map[i][j];
			else {
				_map[i][j] = max(_map[i][j - 1], _map[i - 1][j]) + _map[i][j];
			}
		}
	}
	cout << _map[n][m] << '\n';
	return 0;
}

BFS·Î ÇØ°á

#include<bits/stdc++.h>
using namespace std;
int _map[1001][1001];
bool check[1001][1001];
int answer[1001][1001];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> _map[i][j];
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	answer[0][0] = _map[0][0];
	while (!q.empty()){
		int x, y; tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 2; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n){
				if (check[ny][nx] == false){
					q.push(make_pair(nx, ny));
					check[ny][nx] = true;
					answer[ny][nx] = answer[y][x] + _map[ny][nx];
				}
				else if (answer[ny][nx] < answer[y][x] + _map[ny][nx]){
					q.push(make_pair(nx, ny));
					answer[ny][nx] = answer[y][x] + _map[ny][nx];
				}

			}
		}
	}
	cout << answer[n - 1][m - 1];
	return 0;
}
*/