#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		int a[101] = { 0, };
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n, greater<>());
		cin >> n;
		int b[101] = { 0, };
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(b, b + n, greater<>());
		int i = 0;
		bool flag = false;
		while (a[i] || b[i]) {
			if (a[i] > b[i]) {
				cout << "A\n";
				flag = true;
				break;
			}
			else if (a[i] < b[i]) {
				cout << "B\n";
				flag = true;
				break;
			}
			i++;
		}
		if (flag) continue;
		cout << "D\n";
	}
	return 0;
}