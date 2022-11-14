#include<bits/stdc++.h>
using namespace std;
int egg[1'010];
pair<int, int> price;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> egg[i];
	}
	int buy = min(n, m);
	sort(egg, egg + m);
	int ans = 0, idx = 0, k = min(n, n);
	for (int i = 1; i <= k; i++) {
		if (ans <= i * egg[m - i]) ans = i * egg[m - i], idx = i;
	}

	cout << egg[m - idx] << ' ' << ans << '\n';
	return 0;
}