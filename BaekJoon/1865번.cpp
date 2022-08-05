#include<bits/stdc++.h>
using namespace std;
#define INF 2100000000
struct edge {
	int s, e, t;
};
bool Bellman_Ford(int n, vector<edge> v) {
	vector<int> Dist(n + 1, INF);
	int s, e, t;
	Dist[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < v.size(); j++) {
			s = v[j].s;
			e = v[j].e;
			t = v[j].t;
			if (Dist[e] > Dist[s] + t) {
				Dist[e] = Dist[s] + t;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		s = v[i].s;
		e = v[i].e;
		t = v[i].t;
		if (Dist[e] > Dist[s] + t)
			return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, w; cin >> n >> m >> w;
		vector<edge> v;
		for (int i = 0; i < m; i++) {
			int s, e, t; cin >> s >> e >> t;
			v.push_back({ s, e , t });
			v.push_back({ e, s , t });
		}
		for (int i = 0; i < w; i++) {
			int s, e, t; cin >> s >> e >> t;
			v.push_back({ s,e,-t });
		}

		if (Bellman_Ford(n, v))cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define INF 2100000000
typedef vector<pair<pair<int, int>, int>> vertex;
int Dist[510];
void Bellman_Ford(int n, vertex v) {
	fill(&Dist[0], &Dist[0] + 510, INF);
	int s, e, t;
	Dist[1] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < v.size(); j++) {
			s = v[j].first.first;
			e = v[j].first.second;
			t = v[j].second;
			if (Dist[e] > Dist[s] + t) {
				Dist[e] = Dist[s] + t;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		s = v[i].first.first;
		e = v[i].first.second;
		t = v[i].second;
		if (Dist[e] > Dist[s] + t) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, w; cin >> n >> m >> w;
		vertex v;
		for (int i = 0; i < m; i++) {
			int s, e, t; cin >> s >> e >> t;
			v.push_back({ {s, e} , t });
			v.push_back({ {e, s} , t });
		}
		for (int i = 0; i < w; i++) {
			int s, e, t; cin >> s >> e >> t;
			v.push_back({ {s, e}, -t });
		}
		Bellman_Ford(n, v);
	}
	return 0;
}
*/