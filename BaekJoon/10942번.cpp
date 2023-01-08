#include<bits/stdc++.h>
using namespace std;
int num[2001];
int n, m;
bool dp[2001][2001] = { false };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++) {//팰린드롭 길이 1 
		dp[i][i] = true;
	}
	for (int i = 1; i <= n - 1; i++) {//팰린드롭 길이 2 
		if (num[i] == num[i + 1])dp[i][i + 1] = true;
	}
	for (int len = 3; len <= n; len++) {//팰린드롭 길이 3 이상 
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			if (num[i] == num[j] && dp[i + 1][j - 1])dp[i][j] = true;
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int s, e;
		cin >> s >> e;
		if (dp[s][e] == true)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}