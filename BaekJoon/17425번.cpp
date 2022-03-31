#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
long long num, dp[MAX + 10], s[MAX + 10];
void init() {
	dp[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		for (int j = 1; j * i <= MAX; j++) {
			dp[i * j] += i;
		}
		dp[i] += 1;
	}
	for (int i = 1; i <= MAX; i++)
		s[i] = s[i - 1] + dp[i];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	init();
	while (t--) {
		cin >> num;
		cout << s[num] << '\n';
	}
	return 0;
}