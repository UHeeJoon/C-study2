#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr int MOD = 1'000'000'007;
int main()
{
	FAST_IO;
	vector<int> fibonacci(51, 1);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		fibonacci[i] = (fibonacci[i] + fibonacci[i - 2] + fibonacci[i - 1]) % MOD;
	}
	cout << fibonacci[n] << '\n';
	return 0;
}