#include<bits/stdc++.h>
using namespace std;
int n, m, r, cnt = 1;
vector<int> v[100010];
int order[100010];
void bfs(int R) {
	queue<int> q;
	q.push(R);
	order[R] = cnt;
	while (!q.empty()) {
		R = q.front(); q.pop();
		sort(v[R].begin(), v[R].end(), greater<>());
		for (auto next : v[R]) {
			if (order[next] == 0) {
				q.push(next);
				order[next] = ++cnt;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << order[i] << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int tmp, tmp2; cin >> tmp >> tmp2;
		v[tmp].push_back(tmp2);
		v[tmp2].push_back(tmp);
	}

	bfs(r);
	return 0;
}