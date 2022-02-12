#include<iostream>
using namespace std;
int t, a, b;
int gcd(int x, int y) {
	if (y)
		return gcd(y, x % y);
	return x;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a * b / gcd(a, b) << "\n";
	}
	return 0;
}