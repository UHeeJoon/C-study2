#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(3); cout << fixed;
	double a, b, c;
	int i = 0;
	while (++i) {
		cin >> a >> b >> c;
		if (!a && !b && !c)break;
		if (a == -1) {
			cout << "Triangle #" << i;
			if (c * c - b * b > 0)
				cout << "\na = " << sqrt(c * c - b * b) << '\n';
			else
				cout << "\nImpossible.\n";
		}
		else if (b == -1) {
			cout << "Triangle #" << i;
			if (c * c - a * a > 0)
				cout << "\nb = " << sqrt(c * c - a * a) << '\n';
			else
				cout << "\nImpossible.\n";
		}
		else {
			cout << "Triangle #" << i;
			if (a * a + b * b > 0)
				cout << "\nc = " << sqrt(a * a + b * b) << '\n';
			else
				cout << "\nImpossible.\n";
		}
		cout << '\n';
	}
	return 0;
}