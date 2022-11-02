#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < 5; i++) {
		if (i == 1 || i == 3) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n * 5; k++) {
					cout << '@';
				}
				cout << '\n';
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n * 5; k++) {
					if (k / n == 0 || k / n == 4) cout << '@';
					else cout << ' ';
				}
				cout << '\n';
			}
		}
	}
	return 0;
}