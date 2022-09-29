#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
int arr[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long ans = 0;
	int sum = 0, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; i++) {
		ans += (long long)arr[i] * (sum - arr[i]);
	}
	cout << ans / 2 << '\n';
	return 0;
}