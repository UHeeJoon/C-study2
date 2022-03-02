#include<iostream>
#include<string>
using namespace std;
string s;
int ret, tmp, num[10];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	for (int i = 0; i < (int)s.length(); i++)
		num[s[i] - '0']++;
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		if (ret < num[i]) {
			ret = num[i];
		}
	}
	tmp = (num[6] + num[9]) & 1 ? (num[6] + num[9] + 1) / 2 : (num[6] + num[9]) / 2;
	cout << (ret > tmp ? ret : tmp) << '\n';
	return 0;
}