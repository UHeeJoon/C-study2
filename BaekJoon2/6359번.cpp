#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int num[110];
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			num[i] = 1;
		for (int i = 2; i <= n; i++) {
			for (int k = i; k <= n; k += i) {
				if (!num[k])
					num[k] = 1;
				else
					num[k] = 0;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (num[i])
				cnt++;
		cout << cnt << '\n';
	}
	return 0;
}