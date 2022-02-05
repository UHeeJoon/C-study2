#include<iostream>
#include<queue>
using namespace std;
#define MAX 1001
int arr[MAX][MAX], n, m, cnt;
bool visited[MAX];
queue<int> q;
void bfs(int v) {
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		v = q.front(); q.pop();
		for (auto i = 1; i <= n; i++) {
			if (arr[v][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		arr[u][v] = 1, arr[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt << "\n";
}

/*
#include<iostream>
#include<vector>
using namespace std;
vector<int> vec[1001];
bool visited[1001];
int n, m, cnt;
void dfs(int y) {
	visited[y] = true;
	for (int i = 0; i < (int)vec[y].size(); i++) {
		int x = vec[y][i];
		if (!visited[x]) {
			dfs(x);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << "\n";
}
*/