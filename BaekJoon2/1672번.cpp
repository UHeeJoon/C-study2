#include<bits/stdc++.h>
using namespace std;
string check(string str) {
	if (str == "AA" || str == "CA" || str == "TG" || str == "GT" || str == "AC")
		return "A";
	else if (str == "AG" || str == "GA" || str == "CC")
		return "C";
	else if (str == "GC" || str == "CG" || str == "TT")
		return "T";
	else
		return "G";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	string str; cin >> str;
	reverse(str.begin(), str.end());
	string tmp;
	tmp.push_back(str[0]);
	for (int i = 1; i < str.length(); i++) {
		tmp.push_back(str[i]);
		tmp = check(tmp);
	}
	cout << tmp << '\n';
	return 0;
}