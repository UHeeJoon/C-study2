#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	if (!n) {
		cout << 0 << '\n';
		return 0;
	}
	vector<int> v(n);
	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}
	int sum = 0, cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		if (sum == m) {
			sum = 0;
			cnt++;
		}
		else if (sum > m) {
			sum = v[i];
			cnt++;
		}
	}

	cout << (sum > 0 ? cnt + 1 : cnt) << '\n';
	return 0;
}