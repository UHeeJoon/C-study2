#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> _map;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		_map[a] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (_map[a])cnt++;
	}
	cout << n + m - cnt * 2 << '\n';
	return 0;
}

