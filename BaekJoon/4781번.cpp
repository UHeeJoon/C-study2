#include<bits/stdc++.h>
using namespace std;
#define MAX 10010
#define INF 2147483647
int n;
double m;
int dp[MAX];
pair<int, double> calPrice[MAX / 2];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> n >> m;
		if (!n && !m)break;
		for (int i = 0; i < n; i++) {
			cin >> calPrice[i].first >> calPrice[i].second;
			dp[(int)(calPrice[i].second * 100.0 + 0.5)] = calPrice[i].first;
		}
		//sort(calPrice, calPrice + n, [](pair<int, double>a, pair<int, double> b)->bool {return a.second < b.second; });
		for (int i = 0; i < n; i++) {
			for (int j = (int)(calPrice[i].second * 100.0 + 0.5); j <= int(m * 100.0 + 0.5); j++) {
				dp[j] = max(dp[j], calPrice[i].first + dp[j - (int)(calPrice[i].second * 100.0 + 0.5)]);
			}
		}
		cout << dp[(int)(m * 100.0 + 0.5)] << '\n';
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

constexpr int mxM = 100;
int n, dp[mxM * 100 + 5];
double m;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n >> m, !(n == 0 && m == 0.0))
	{
		memset(dp, 0, sizeof(dp));
		int M = static_cast<int>(m * 100.0 + 0.5); // +0.5를 왜 해야할까요?
		while (n--)
		{
			int c;
			double p;
			cin >> c >> p;
			int P = static_cast<int>(p * 100.0 + 0.5); // +0.5를 왜 해야할까요?
			for (int idx = P; idx <= M; ++idx)
				dp[idx] = max(dp[idx], dp[idx - P] + c);
		}
		cout << dp[M] << '\n';
	}
	return 0;
}
*/