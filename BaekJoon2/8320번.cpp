#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; i * j <= n && j <= n; j++) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}