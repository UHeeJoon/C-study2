#include<bits/stdc++.h>
using namespace std;
int arr[110];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int sum = 0, _max = -987654321;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i > k) {
			_max = max(_max, sum);
			sum -= arr[i - k];
			sum += arr[i];
		}
		else {
			sum += arr[i];
		}
	}
	cout << max(_max, sum) << '\n';
	return 0;
}