#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, m; cin >> n >> m;
	int _max = m;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		m = m + a - b;
		if (m < 0) flag = true;
		_max = max(_max, m);
	}
	cout << (flag ? 0 : _max) << '\n';
	return 0;
}