#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> v;
	while (m--) {
		int a, b; cin >> a >> b;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), [](int a, int b) {
		return a > b;
		});
	int cnt(0);
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] < n) {
			cnt += (n - v[i]);
		}
	}
	cout << cnt << '\n';
	return 0;
}