#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[101] = { 0,1,1,1,2,2 }, T, n;
void padoban() {
	for (int i = 6; i < 101; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> T;
	padoban();
	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}