#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [](int a, int b) {
		return a > b;
		});
	for (int i = 0; i < n - 2; i++) {
		if (v[i] < v[i + 1] + v[i + 2]) {
			cout << v[i] + v[i + 1] + v[i + 2] << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}