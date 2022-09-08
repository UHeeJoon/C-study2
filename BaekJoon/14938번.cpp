#include<bits/stdc++.h>
using namespace std;
#define MAX 110
#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
int n, m, r;
int field[MAX];
int dist[MAX];
vector<pair<int, int>> v[MAX];
int getItem(int start) {
	fill(&dist[0], &dist[0] + MAX, INF);
	dist[start] = 0;
	queue<pair<int, int>> q;
	q.push({ 0,start });
	while (!q.empty()) {
		int cost = -q.front().first;
		int cur = q.front().second;
		q.pop();
		for (auto a : v[cur]) {
			int next = a.first;
			int nCost = cost + a.second;
			if (dist[next] < nCost)continue;
			q.push({ -nCost, next });
			dist[next] = nCost;
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (dist[i] <= m)sum += field[i];
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> field[i];
	while (r--) {
		int a, b, l; cin >> a >> b >> l;
		v[a].push_back({ b,l });
		v[b].push_back({ a,l });
	}
	int _max = 0;
	for (int i = 1; i <= n; i++) {
		_max = max(_max, getItem(i));
	}
	cout << _max << '\n';
	return 0;
}