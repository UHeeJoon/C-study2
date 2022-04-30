#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	int cnt = 1;
	bool flag = false;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == s[i + 1])
			cnt++;
		else
			cnt = 1;
		if (cnt >= 7) {
			flag = true;
			break;
		}
	}
	cout << (flag ? "YES\n" : "NO\n");
	return 0;
}