#include<bits/stdc++.h>
#define MAX 1000010
using namespace std;
int n;
int dp[MAX], before[MAX];
void make_One() {
	dp[1] = 0;
	before[1] = -1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		before[i] = i - 1;
		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
			dp[i] = dp[i / 2] + 1;
			before[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
			dp[i] = dp[i / 3] + 1;
			before[i] = i / 3;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
	cin >> n;
	make_One();
	cout << dp[n] << "\n";
	int idx = n;
	while (idx != -1) {
		cout << idx << " ";
		idx = before[idx];
	}
	return 0;
}
/*
#include <iostream> 
#include <algorithm> 
using namespace std;
int n, dp[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) { dp[i] = i; }
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2]);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3]);
		}
		dp[i] = min(dp[i], dp[i - 1]) + 1;
	}
	cout << dp[n] - 1 << "\n";
	while (n != 0) {
		cout << n << " ";
		if (dp[n] == dp[n - 1] + 1) {
			n = n - 1;
		}
		else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1) {
			n = n / 2;
		}
		else if (n % 3 == 0 && dp[n] == dp[n / 3] + 1) {
			n = n / 3;
		}
	}
	return 0;
}
*/