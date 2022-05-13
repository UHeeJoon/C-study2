#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
int n, s;
int stone[MAX];
bool visited[MAX];
int bfs(int x) {
	int cnt = 1;
	visited[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int x1 = q.front();
		q.pop();
		for (int next : {x1 + stone[x1], x1 - stone[x1]}) {
			if (next < 1 || next > n || visited[next]) continue;
			visited[next] = true;
			q.push(next);
			cnt++;
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stone[i];
	cin >> s;
	cout << bfs(s) << '\n';
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
int n, s;
int stone[MAX];
bool visited[MAX];
void dfs(int x) {
	if (x<1 || x>n || visited[x])return;
	visited[x] = true;
	dfs(x + stone[x]);
	dfs(x - stone[x]);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stone[i];
	cin >> s;
	int cnt = 0;
	dfs(s);
	for (int i = 1; i <= n; i++)
		if (visited[i]) cnt++;
	cout << cnt << '\n';
	return 0;
}
*/