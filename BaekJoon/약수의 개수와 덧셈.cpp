#include<iostream>
#include<cmath>
using namespace std;
int l, r, result;
int divisor(int n) {
	int sum = 0;
	for (int i = 1; i < sqrt(n) + 1; i++) {
		if (n % i == 0) {
			if (i * i == n)
				sum += 1;
			else
				sum += 2;
		}
	}
	return sum;
}
int main() {
	cin >> l >> r;
	for (int i = l; i < r + 1; i++) {
		if (divisor(i) & 1) {
			result -= i;
		}
		else
			result += i;
	}
	cout << result <<"\n";
}