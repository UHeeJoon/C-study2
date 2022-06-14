#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1010];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int tmp; cin >> tmp;
			arr[i] = arr[i - 1] + tmp;
		}
		int _max = -987654321;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				_max = max(_max, arr[i] - arr[j]);
			}
		}
		cout << _max << '\n';
	}
	return 0;
}