#include<bits/stdc++.h>
using namespace std;
const int MAX = 100010;
int N, M;
int cost[MAX];
bool check(int mid) {
	int cnt = 1;
	int sum = mid;
	for (int i = 0; i < N; i++) {
		if (mid < cost[i])
			return false;
		if (sum - cost[i] < 0) {
			sum = mid;
			cnt++;
		}
		sum -= cost[i];
	}
	return M >= cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		sum += cost[i];
	}
	int low = 1, high = sum;
	int result = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid)) {
			result = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << result << "\n";
	return 0;
}