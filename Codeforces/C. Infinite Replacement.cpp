#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s, s2; cin >> s >> s2;
		bool flag = false;
		long long cnt = 0;
		if (s2 == "a" && s2.length() == 1) {
			cout << 1 << '\n';
			continue;
		}
		for (int i = 0; i < s2.length(); i++)
			if (s2[i] == 'a') {
				cout << -1 << '\n';
				flag = true;
				break;
			}
		if (flag) continue;
		long long tmp = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a')
				tmp++;
		}
		if (tmp != 0) {
			cnt = (long long)pow(2, tmp);
		}
		cout << cnt << '\n';
	}
	return 0;
}