#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int up(0), down(0);
	string s; cin >> s;
	for (int i = 0; i < (int)s.length(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			up++;
		if ('a' <= s[i] && s[i] <= 'z')
			down++;
	}
	if (up > down)
		for (int i = 0; i < (int)s.length(); i++)
			s[i] = toupper(s[i]);
	else
		for (int i = 0; i < (int)s.length(); i++)
			s[i] = tolower(s[i]);
	cout << s << '\n';
	return 0;
}