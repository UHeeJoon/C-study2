#include<bits/stdc++.h>
using namespace std;
int arr[52], dp[52][1010], N, S, M;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S >> M;
	fill(&dp[0][0], &dp[51][1009], -1);
	int _max = -1;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	dp[0][S] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j] == -1)continue;
			if (j + arr[i] <= M) dp[i][j + arr[i]] = 1;
			if (j - arr[i] >= 0) dp[i][j - arr[i]] = 1;
		}
	}
	for (int i = 0; i <= M; i++)
		if (dp[N][i] == 1)
			_max = max(_max, i);
	cout << _max << '\n';
	return 0;
}