#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, d;  cin >> n >> d;
		int cnt = 0;
		while (n--) {
			double v, f, c; cin >> v >> f >> c;
			if (v / c * f >= d)
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}