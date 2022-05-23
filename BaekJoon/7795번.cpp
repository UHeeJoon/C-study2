#include<bits/stdc++.h>
using namespace std;
int A[20010], B[20010];
int n, m;
int binarySearch(int num) {
	int high = m - 1, low = 0;
	int cnt = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (B[mid] < num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return low;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cin >> A[i];
		sort(A, A + n);
		for (int i = 0; i < m; i++)
			cin >> B[i];
		sort(B, B + m);
		for (int i = 0; i < n; i++) {
			cnt += binarySearch(A[i]);
		}
		cout << cnt << '\n';
	}
	return 0;
}