#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr int mod = 1'000'000'000;
int fibonacci[1'000'010];
int main() {
	FAST_IO;
	int n;  cin >> n;

	int sign = 0;
	if (n == 0) sign = 0;
	else if (n >= 0 || n & 1) {
		sign = 1;
	}
	else {
		sign = -1;
	}
	if (n < 0) n = -n;
	fibonacci[0] = 0; fibonacci[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % mod;
	}
	cout << sign << '\n';
	cout << fibonacci[n] << '\n';
	return 0;
}