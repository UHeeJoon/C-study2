#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, r, b;
string s;
int check(char c, int rOb) {
	int _min = 987654321, ret = 0, cnt = 0;
	while (s[ret++] == c) cnt++;
	_min = min(_min, rOb - cnt);
	ret = n - 1, cnt = 0;
	while (s[ret--] == c) cnt++;
	_min = min(_min, rOb - cnt);
	return _min;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') r++;
		else b++;
	}
	cout << min(check('R', r), check('B', b)) << "\n";
}