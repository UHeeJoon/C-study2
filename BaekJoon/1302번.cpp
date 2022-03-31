#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, cnt = 0; cin >> n;
	map<string, int> _map;
	vector<string> v;
	while (n--) {
		string s; cin >> s;
		_map[s]++;
		cnt = max(cnt, _map[s]);
	}
	for (auto a : _map)
		if (a.second == cnt)
			v.push_back(a.first);
	sort(v.begin(), v.end());
	cout << v[0] << '\n';
	return 0;
}