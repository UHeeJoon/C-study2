#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	int count = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '4' || s[i] == '7')
			count++;
	cout << ((count == 4 || count == 7) ? "YES\n" : "NO\n");
	return 0;
}