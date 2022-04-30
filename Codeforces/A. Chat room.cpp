#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	string s1 = "hello";
	int cnt = 0, j = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s1[j]) {
			cnt++;
			j++;
		}
	}
	cout << (cnt == 5 ? "YES\n" : "NO\n");
	return 0;
}