#include<bits/stdc++.h>
using namespace std;
int str[52][27];
int _max[52];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			str[j][c - 'A']++;
			_max[j] = max(_max[j], str[j][c - 'A']);
		}
	}
	int sum = 0;
	string s = "";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 26; j++) {
			if (str[i][j] == _max[i]) {
				s.push_back(char(j + 'A'));
				sum += n - _max[i];
				break;
			}
		}
	}
	cout << s << '\n' << sum << '\n';
	return 0;
}