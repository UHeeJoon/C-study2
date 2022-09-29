#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
int arr[MAX];
int n;
void input(int idx, int num) {
	while (idx <= n + 1) {
		arr[idx] += num;
		idx += (idx & -idx);
	}
}
int sum(int idx) {
	int _sum = 0;
	while (idx) {
		_sum += arr[idx];
		idx -= (idx & -idx);
	}
	return _sum;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		input(i, num);
	}
	int m; cin >> m;
	while (m--) {
		int i, j; cin >> i >> j;
		cout << sum(j) - sum(i - 1) << '\n';
	}
	return 0;
}