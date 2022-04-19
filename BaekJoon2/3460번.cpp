#include<bits/stdc++.h>
using namespace std;
void bin(int n) {
	string s = "";
	while (n) {
		s += n % 2 == 0 ? '0' : '1';
		n /= 2;
	}
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '1')
			cout << i << ' ';
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; 
	while (t--) {
		int n; cin >> n;
		bin(n);
	}
	return 0;
}