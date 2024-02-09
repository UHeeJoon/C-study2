#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
constexpr int MOD = 14579;
int main()
{
	FAST_IO;
	int a, b; cin >> a >> b;
	int sum = (!(a & 1) ? (a + 1) * (a / 2) : a * (a / 2) + a) % MOD;
	int answer = sum;
	for (int i = a + 1; i <= b; i++) {
		sum = (sum + i) % MOD;
		answer = (answer * sum) % MOD;
	}
	cout << answer << '\n';
	return 0;
}