#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
string s, tmp, Binary[8] = { "000","100","010","110","001","101","011","111"};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string n; cin >> n;
	reverse(n.begin(), n.end());
	if (n.length()%3 !=0) {
		while ((int)n.length()%3 != 0)
			n.push_back('0');
	}
	for (int i = 0; i < (int)n.length(); i += 3) {
		tmp = n.substr(i,3);
		for (int i = 0; i < 8; i++) {
			if (Binary[i] == tmp)
				s += to_string(i);
		}
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
	return 0;
}

/*
	if (n[0] == '0')
		s = "0";
	else if (n[0] == '1')
		s = "1";
	else if (n[0] == '2')
		s = "10";
	else if (n[0] == '3')
		s = "11";
	else
		s = Binary[n[0] - '0'];
*/