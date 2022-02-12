#include<iostream>
using namespace std;
int main() {
	int n, k, result = 1;
	cin >> n >> k;
	int temp = n - k;
	for (int i = k + 1; i <= n; i++) {
		if (i <= n - k) {
			temp -= 1;;
			continue;
		}
		result *= i;
	}
	while (temp > 1) {
		result /= temp;
		temp -= 1;
	}
	cout << result << "\n";
}