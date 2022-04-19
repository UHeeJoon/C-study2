#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a = (int)sqrt(n), b = (int)sqrt(n);
	if (a * b >= n)
		cout << a << ' ' << b << '\n';
	else if ((a + 1) * b >= n)
		cout << a + 1 << ' ' << b << '\n';
	else if ((a + 1) * (b + 1) >= n)
		cout << a + 1 << ' ' << b + 1 << '\n';
	return 0;
}