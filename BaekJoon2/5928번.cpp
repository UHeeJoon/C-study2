#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int d, h, m; cin >> d >> h >> m;
	d -= 11, h += d * 24;
	h -= 11, m += h * 60;
	m -= 11;
	cout << (m < 0 ? -1 : m) << '\n';
	return 0;
}