#include<bits/stdc++.h>
using namespace std;
int num[101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int zero = 0;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			if (num[i] == 0)
				zero++;
		}
		int cnt = 0;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (num[i] == num[j])
					cnt++;
		if (zero == 0) {
			if (cnt >= 1)
				cout << n << '\n';
			else
				cout << n + 1 << '\n';
		}
		else
			cout << n - zero << '\n';
	}
	return 0;
}