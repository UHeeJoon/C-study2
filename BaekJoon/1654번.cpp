#include<bits/stdc++.h>
using namespace std;
int K, N, ans;
int line[10001];
unsigned int mid, high, low;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> line[i];
		high = max((int)high, line[i]);
	}
	low = 1, ans = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += line[i] / mid;
		if (cnt >= N) {
			low = mid + 1;
			ans = max(ans, (int)mid);
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}