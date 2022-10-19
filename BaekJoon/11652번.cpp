#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	map<ll, int> _map;
	int n; cin >> n;
	ll num = 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ll ord; cin >> ord;
		_map[ord]++;
		if (_map[ord] > ans) {
			ans = _map[ord];
			num = ord;
		}
		else if (_map[ord] == ans) {
			num = min(num, ord);
		}
	}
	cout << num << '\n';
	return 0;
}