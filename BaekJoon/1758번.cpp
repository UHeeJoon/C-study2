#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
int tip[100'000];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long tipSum = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tip[i];
	}
	sort(tip, tip + n, [](int a, int b) {
		return a > b;
		});
	for (int i = 0; i < n; i++) {
		int tmp = tip[i] - i < 0 ? 0 : tip[i] - i;
		tipSum += tmp;
	}
	cout << tipSum << '\n';
	return 0;
}