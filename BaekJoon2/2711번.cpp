#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		cout << s.replace(n - 1, 1, "") << '\n';
	}
	return 0;
}