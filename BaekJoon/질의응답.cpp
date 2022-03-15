#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
int dp[1001], card[1001], n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int m, n;
	scanf("%d %d", &m, &n);
	int i, j;
	for (i = m; i <= n; i++) {
		for (j = 2; j * j  <= i; j++) {
			if (i % j == 0 && i == j) {
				printf("%d\n", i);
				break;
			}
			else if (i % j == 0 && i != j) 
				break;
			
		}
	}
	return 0;
}