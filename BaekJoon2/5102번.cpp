#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int a, b; cin >> a >> b;
		if (!a && !b)
			break;
		if (a - b < 2) cout << 0 << ' ' << 0 << '\n';
		else if ((a - b) & 1)cout << (a - b - 3) / 2 << ' ' << 1 << '\n';
		else cout << (a - b) / 2 << ' ' << 0 << '\n';
	}
	return 0;
}