#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
	if (y)
		return gcd(y, x % y);
	return x;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long num, num2;
	cin >> num >> num2;
	long long Gcd = gcd(num, num2);
	cout << num * num2 / Gcd << '\n';
	return 0;
}