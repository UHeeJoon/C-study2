#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int sum = 0, sum2 = 0;
		for (int i = 0; i < 6; i++) {
			char a; cin >> a;
			if (i < 3)
				sum += (a - '0');
			else
				sum2 += (a - '0');
		}
		if (sum == sum2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}