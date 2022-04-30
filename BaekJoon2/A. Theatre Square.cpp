#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, m, a; cin >> n >> m >> a;
	n = n % a == 0 ? n / a : n / a + 1;
	m = m % a == 0 ? m / a : m / a + 1;
	cout << n * m << '\n';
	return 0;
}