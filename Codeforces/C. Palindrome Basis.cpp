#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int dp[40010];
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	int tmp = 0;
	for (int i = 1; i < 40005; i++) {
		string a = to_string(i);
		string ret = a.substr(0, a.size() / 2);
		reverse(a.begin(), a.end());
		string ret2 = a.substr(0, a.size() / 2);
		if (ret == ret2)
			v.push_back(i);
	}
	dp[0] = 1;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = v[i]; j <= 40000; j++) {
			dp[j] = (dp[j] + dp[j - v[i]]) % MOD;
		}
	}
	while (t--) {
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
}