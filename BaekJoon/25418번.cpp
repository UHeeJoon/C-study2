#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int dp[1'000'001];
int main()
{
	FAST_IO;
	fill(dp, dp + 1'000'000, 987654321);
	int a, k; cin >> a >> k;
	dp[a] = 0;
	for (int i = a + 1; i <= k; i++)
	{
		dp[i] = (i & 1) ? dp[i - 1] + 1 : min(dp[i - 1], dp[i / 2]) + 1;
	}
	cout << dp[k] << '\n';
	return 0;
}