#include<bits/stdc++.h>	
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double a, b;
	cout.precision(2); cout << fixed;
	while (cin.eof() == 0 && cin >> a >> b) {
		cout << a / b << '\n';
	}
	return 0;
}