#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	stack<char> S;
	string s;
	int total = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			S.push(s[i]);
		}
		else if (s[i] == ')' && s[i - 1] == '(') {
			S.pop();
			total += S.size();
		}
		else {
			total++;
			S.pop();
		}
	}
	cout << total << '\n';
	return 0;
}