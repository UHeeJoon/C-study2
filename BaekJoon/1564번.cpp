#include<bits/stdc++.h>
using namespace std;
int main()
{
	constexpr long long MOD = 1e12;
	int n; cin >> n;
	long long mul = 1;
	for (int i = 2; i <= n; i++) {
		mul *= i;
		while (mul % 10 == 0) {
			mul /= 10;
		}
		mul %= MOD;
	}
	printf("%05lld", mul % 100'000);
	return 0;
}