#include<bits/stdc++.h>
using namespace std;
int gcd(const int a, const int b) {
	return a % b ? gcd(b, a % b) : b;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
	int molecule = a1 * b2 + a2 * b1, denominator = b1 * b2;
	const int m_gcd = gcd(molecule, denominator);
	molecule = molecule / m_gcd;
	denominator = denominator / m_gcd;
	cout << molecule << ' ' << denominator << '\n';
	return 0;
}