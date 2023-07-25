#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using ll = long long;
constexpr int MOD = (int)1e9 + 7;

constexpr int MN = 4000000;
ll fac[MN + 10], facinv[MN + 10], inv[MN + 10];
void fac_init() {
	fac[0] = facinv[0] = inv[1] = 1;
	for (int i = 1; i <= MN; i++) {
		inv[i + 1] = (MOD - MOD / (i + 1)) * inv[MOD % (i + 1)] % MOD;
		fac[i] = fac[i - 1] * i % MOD;
		facinv[i] = facinv[i - 1] * inv[i] % MOD;
	}
}
ll C(ll n, ll r) {
	return ((fac[n] * facinv[r]) % MOD) * facinv[n - r] % MOD;
}
int main()
{
	FAST_IO;
	ll n, k; cin >> n >> k;
	fac_init();
	cout << C(n, k);
	return 0;
}