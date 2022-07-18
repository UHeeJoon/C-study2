#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; getline(cin, s);
	string s2; cin >> s2;
	int idx = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			if (s[i] - s2[idx] <= 0)
				cout << char('z' + (s[i] - s2[idx]));
			else
				cout << char(s[i] - (s2[idx] - 'a' + 1));

		}
		else {
			cout << ' ';
		}
		idx = (idx + 1) % s2.length();
	}
	return 0;
}