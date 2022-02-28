#include <iostream>
#include<cmath>
using namespace std;
bool isPrime(long long n) {
	if (n == 0 || n == 1)return false;
	if (n == 2) return true;
	for (long long i = 2; i <= sqrt(n); i++)
		if (n % i == 0)return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long t, n; cin >> t;
	while (t--) {
		cin >> n;
		for (long long i = n;; i++) {
			if (isPrime(i)) {
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}