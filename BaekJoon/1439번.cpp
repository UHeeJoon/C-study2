#include<iostream>
#include<string>
using namespace std;
string s;
int cnt, cnt2;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> s;
	int tmp = 1, tmp2 = 1;
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == '0') {
			if (tmp)
				cnt++;
			tmp = 0;
			tmp2 = 1;
		}
		else {
			if (tmp2)
				cnt2++;
			tmp2 = 0;
			tmp = 1;
		}
	}
	cout << (cnt < cnt2 ? cnt : cnt2) << "\n";
}