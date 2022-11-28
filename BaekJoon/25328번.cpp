#include<bits/stdc++.h>
using namespace std;
map<string, int> _map;
void backtracking(int idx, int k, string& str, string tmp, int cnt) {
	if (cnt == k) {
		_map[tmp]++;
		return;
	}
	for (int i = idx; i < str.length(); i++) {
		backtracking(i + 1, k, str, tmp + str[i], cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x, y, z; int k;
	cin >> x >> y >> z >> k;
	backtracking(0, k, x, "", 0);
	backtracking(0, k, y, "", 0);
	backtracking(0, k, z, "", 0);
	int cnt = 0;
	for (auto a : _map) {
		if (a.second > 1) {
			cout << a.first << '\n';
			cnt++;
		}
	}
	if (!cnt)cout << -1 << '\n';
	return 0;
}