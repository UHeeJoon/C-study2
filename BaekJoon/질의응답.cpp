#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool isprime(int n) {
	if (n == 2) return true;
	for (int j = 2; j < n; j++) {
		if (n % j == 0) return false;
	}
	return true;
}
int main() {
	int tmp(0);
	for (int i = 2; i <= 523; i++) {
		if (isprime(i))
			tmp++;
	}
	cout << 999 + tmp << "\n";
	return 0;
}