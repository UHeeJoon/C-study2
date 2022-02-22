#include<iostream>
#include<algorithm>
using namespace std;
int n, m, six = 987654321, one = 987654321;
int main() {
	cin >> n >> m;
	while (m--) {
		int six_temp, one_temp;
		cin >> six_temp >> one_temp;
		if (six_temp < six)
			six = six_temp;
		if (one_temp < one)
			one = one_temp;
	}
	m = n / 6 * six + n % 6 * one;
	six = (n / 6 + 1) * six;
	one = one * n;
	cout << min(m, min(six, one)) << "\n";
}