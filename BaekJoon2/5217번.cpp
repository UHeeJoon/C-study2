#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << "Pairs for " << n << ":";
		int i = 1, j = n - i;
		for (i; i < j;) {
			if (i != 1) cout << ',';
			cout << ' ' << i << ' ' << j;
			j = n - ++i;
		}
		cout << '\n';
	}
	return 0;
}