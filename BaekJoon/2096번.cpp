#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int minDp[2][5] = { {987654321, 987654321 , 987654321 , 987654321 , 987654321},
						{987654321, 987654321 , 987654321 , 987654321 , 987654321} };
	int maxDp[2][5] = { 0, };
	int n; cin >> n;
	for (int i = 1; i <= 3; i++) {
		cin >> minDp[0][i];
		maxDp[0][i] = minDp[0][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= 3; j++) {
			int cur; cin >> cur;
			minDp[i % 2][j] = min({ minDp[(i - 1) % 2][j - 1] + cur, minDp[(i - 1) % 2][j] + cur, minDp[(i - 1) % 2][j + 1] + cur });
			maxDp[i % 2][j] = max({ maxDp[(i - 1) % 2][j - 1] + cur, maxDp[(i - 1) % 2][j] + cur, maxDp[(i - 1) % 2][j + 1] + cur });
		}
	}
	int idx = (n & 1) == 1 ? 0 : 1;
	cout << max({ maxDp[idx][1],maxDp[idx][2], maxDp[idx][3] }) << ' ' << min({ minDp[idx][1],minDp[idx][2], minDp[idx][3] }) << '\n';
	return 0;
}