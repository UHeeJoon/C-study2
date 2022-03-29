#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, sum(0), result(0); cin >> n;
	long long tmp, tmp2;
	cin >> tmp >> tmp2;
	sum = (tmp + tmp2) % MOD;
	result = ((tmp % MOD) * (tmp2 % MOD)) % MOD;
	n -= 2;
	while (n--) {
		cin >> tmp;
		result = (result + (sum * tmp)) % MOD;
		sum = (sum + tmp) % MOD;
	}
	cout << result << '\n';
	return 0;
}