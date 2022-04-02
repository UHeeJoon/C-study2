
#include<bits/stdc++.h>
using namespace std;
int arr[301][301];
int dp[301][301];
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	int k;
	cin >> k;
	while (k--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		cout << dp[x][y] - dp[a - 1][y] - dp[x][b - 1] + dp[a - 1][b - 1] << '\n';
	}
	return 0;
}
/*
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	int cycle;
	int sum;
	int startX, startY;
	int endX, endY;
	int map[310][310];

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin >> map[i][j];
		}
	}
	cin >> cycle;
	while (cycle-- > 0) {
		cin >> startX >> startY;
		cin >> endX >> endY;
		sum = 0;

		for (int i = startX; i <= endX; ++i) {
			for (int j = startY; j <= endY; ++j) {
				sum += map[i][j];
			}
		}
		cout << sum << endl;
	}

	return 0;
}
*/