#include<bits/stdc++.h>
using namespace std;
string s, s2;
int comp() {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 97) s[i] -= 32;
		if (s2[i] >= 97) s2[i] -= 32;
		if (s[i] == s2[i]) continue;
		else if (s[i] < s2[i]) return -1;
		else return 1;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s >> s2;
	cout << comp() << '\n';
	return 0;
}