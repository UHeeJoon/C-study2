#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int l, r, a; cin >> l >> r >> a;
	if (l > r) swap(l, r);
	int tmp = (l + a) - r;
	if (tmp <= 0) cout << (l + a) * 2 << '\n';
	else cout << (r + tmp / 2) * 2 << '\n';
	return 0;
}