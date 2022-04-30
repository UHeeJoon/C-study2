#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int one, two; cin >> one >> two;
		if (one == 0)
			cout << 1 << '\n';
		else {
			cout << one + two * 2 + 1 << '\n';
		}
	}
	return 0;
}