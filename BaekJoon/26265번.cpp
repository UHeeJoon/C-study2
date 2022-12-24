#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector < pair<string, string> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(),
		[](pair<string, string> a, pair<string, string> b) {
			if (a.first == b.first) {
				return a.second > b.second;
			}
			return a.first < b.first;
		});
	cout << '\n';
	for (auto a : v) {
		cout << a.first << ' ' << a.second << '\n';
	}
	return 0;
}