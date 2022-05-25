#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(6); cout << fixed;
	double k, d1, d2;
	cin >> k >> d1 >> d2;
	cout << k * k - ((d1 - d2) / 2) * ((d1 - d2) / 2) << '\n';
	return 0;
}