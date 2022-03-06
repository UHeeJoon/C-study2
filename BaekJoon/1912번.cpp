#include<bits/stdc++.h>
using namespace std;
int n, sum = -987654321, num[100010], dp[100010];
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	dp[0] = num[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(max(dp[i - 1] + num[i], num[i - 1] + num[i]), num[i]);
	}
	for(int i=0;i<n;i++)
		sum = max(dp[i], sum);
	cout << sum << '\n';
	return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, temp, dp;
	int ans;
	cin >> n;
	cin >> temp;
	ans = dp = temp;
	for (int i = 1; i < n; i++) {
		cin >> temp;
		dp = max(temp,temp+dp);
		if (ans < dp)ans = dp;
	}
	cout << ans;
}
*/