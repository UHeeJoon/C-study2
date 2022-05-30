#include<bits/stdc++.h>
using namespace std;
long long n, m, jewel[300001];
long long sum(int num) {
	long long _sum = 0;
	for (int i = 0; i < m; i++)
		_sum += jewel[i] % num == 0 ? jewel[i] / num : jewel[i] / num + 1;
	return _sum;
}
void binarySearch() {
	long long l = 1;
	long long r = 1000000000;
	long long _min = 2100000000;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (sum(mid) <= n) {
			r = mid - 1;
			_min = min(_min, mid);
		}
		else
			l = mid + 1;
	}
	cout << _min << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> jewel[i];
	binarySearch();
	return 0;
}