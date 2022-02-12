#include<iostream>
using namespace std;
#define DIV 10007
#define MAX 1001
int dp[MAX][MAX];
int n, k;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j || j == 0) {
                dp[i][j] = 1; 
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % DIV;
        }
    }
    cout << dp[n][k] <<"\n";
    return 0;
}