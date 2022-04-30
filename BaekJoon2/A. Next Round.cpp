#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int num[51] = { 0, }, cnt(0);
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if (i >= k) {
			if (num[i] == num[k])
				cnt = i;
		}
	}
	if (num[cnt] == 0)
		while (cnt) {
			if (num[cnt] != 0) break;
			cnt--;
		}

	cout << cnt << '\n';
	return 0;
}