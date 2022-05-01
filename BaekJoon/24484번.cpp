#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<int> v[MAX];
bool visited[MAX];
int cnt = 1;
long long dfs(long long r, long long u) {
	long long sum = cnt * u;
	cnt += 1;
	visited[r] = true;
	sort(v[r].begin(), v[r].end(), greater<>());
	for (int i = 0; i < v[r].size(); i++) {
		if (!visited[v[r][i]])
			sum += dfs(v[r][i], u + 1);
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, r; cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout << dfs(r, 0) << '\n';
	return 0;
}