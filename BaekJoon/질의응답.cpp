#include <iostream>

using namespace std;

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	int new_n = n;
	while (1) {
		cnt = cnt + 1;
		new_n = ((new_n / 10) + (new_n % 10)) % 10 + (new_n % 10) * 10;
		if (new_n == n) break;
	}
	cout << cnt;
}