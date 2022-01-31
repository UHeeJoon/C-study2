#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s, tmp, tmp2;
int main() {
	while (1) {
		cin >> s;
		if (s == "0")break;
		tmp = s.substr(0, s.size() / 2);
		reverse(s.begin(), s.end());
		tmp2 = s.substr(0, s.size() / 2);
		if (tmp == tmp2)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}