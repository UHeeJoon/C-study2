#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
unordered_set<string> _set;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++)
		for (int j = 1; j <= s.length() - i; j++) 
			_set.insert(s.substr(i, j));
	cout << _set.size() << '\n';
	return 0;
}