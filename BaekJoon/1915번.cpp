#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int square_row, square_col; cin >> square_row >> square_col;
	vector<vector<int>> dp(square_row + 1, vector<int>(square_col + 1));
	for (int i = 1; i <= square_row; i++)
	{
		string row; cin >> row;
		for (int j = 0; j < square_col; j++)
		{
			if (row[j] == '0')continue;
			dp[i][j + 1] = 1;
		}
	}¤º
	int len = 0;
	for (int i = 1; i <= square_row; i++)
	{
		for (int j = 1; j <= square_col; j++)
		{
			if (!dp[i][j])continue;
			dp[i][j] = min({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] }) + 1;
			len = max(len, dp[i][j]);
		}
	}
	cout << len * len << '\n';
	return 0;
}