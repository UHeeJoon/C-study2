#include<bits/stdc++.h>
using namespace std;
long long n, m, snack[1000001];
long long sum(long long num) {
	long long _sum = 0;
	for (int i = 0; i < m; i++)
		_sum += snack[i] / num;
	return _sum;
}
void binarySearch() {
	long long l = 1;
	long long r = 1000000000;
	long long _max = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (sum(mid) < n)
			r = mid - 1;
		else {
			l = mid + 1;
			_max = max(_max, mid);
		}
	}
	cout << _max << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> snack[i];
	binarySearch();
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int M, N;
int snack[1000000];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int left = 1, right = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> snack[i];
		right = max(right, snack[i]);
	}
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < N; i++)
			cnt += snack[i] / mid;
		if (cnt < M)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left - 1 << "\n";
	return 0;
}
*/