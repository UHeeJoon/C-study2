#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001], A_len, B_len;
char A[1010], B[1010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	A_len = (int)strlen(A), B_len = (int)strlen(B);
	for (int i = 1; i <= A_len; i++) {
		for (int j = 1; j <= B_len; j++) {
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	string s = "";
	cout << dp[A_len][B_len] << '\n';
	while (dp[A_len][B_len]) {
		if (dp[A_len][B_len] == dp[A_len - 1][B_len])A_len--;
		else if (dp[A_len][B_len] == dp[A_len][B_len - 1])B_len--;
		else {
			s += B[B_len - 1];
			A_len--;
			B_len--;
		}
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
	return 0;
}