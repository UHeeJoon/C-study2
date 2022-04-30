#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	vector<char> v;
	for (int i = 0; i < s.length(); i++) {
		if (i % 2 == 0)
			v.push_back(s[i]);
	}
	s = "";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++)
		s = s + v[i] + "+";
	s += v[v.size() - 1];
	cout << s << '\n';
	return 0;
}