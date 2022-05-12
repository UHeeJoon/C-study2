#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, tmp = 987654321; cin >> n;
		int num[55] = { 0, };
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			tmp = min(tmp, num[i]);
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += (num[i] - tmp);
		cout << sum << '\n';
	}
	return 0;
}