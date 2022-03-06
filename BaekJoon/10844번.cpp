#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000000
int dp[110][11], n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) 
				dp[i][j] = dp[i - 1][j + 1];

			else if (j == 9) 
				dp[i][j] = dp[i - 1][j - 1];

			else 
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] %= MOD;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[n][i]) % MOD;
	}
	cout << sum << '\n';
	return 0;
}

/*
#include<iostream>
using namespace std;

#define MODN   1000000000
int way[101][10];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin>>N;

	way[1][0]=0;
	for(int i=1; i<=9; i++)
		way[1][i] = 1;

	for(int i=2; i<=N; i++)
	{
		way[i][0] = way[i-1][1]%MODN;
		for(int j=1; j<=8; j++)
			way[i][j]=(way[i-1][j-1]+way[i-1][j+1])%MODN;
		way[i][9] = way[i-1][8]%MODN;
	}


	int sum = 0;
	for(int i=0; i<=9; i++)
		sum=(sum+way[N][i])%MODN;

	cout<<sum<<'\n';
	return 0;
}

*/