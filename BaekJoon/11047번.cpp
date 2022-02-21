#include<iostream>
using namespace std;
int n, k, cnt, money[12];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
		if (money[i] <= k)
			money[10] = i;
	}
	for (int i = money[10]; i >= 0; i--) {
		cnt += k / money[i];
		k %= money[i];
	}
	cout << cnt << "\n";
}
