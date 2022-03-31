#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	map<string, int> _map;
	vector<string> v;
	int n, m; cin >> n >> m;
	n = n + m;
	while (n--) {
		string s; cin >> s;
		_map[s]++;
		if (_map[s] == 2)
			v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
	return 0;
}