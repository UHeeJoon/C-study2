#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int N, M;
void binarySearch(int sum, int low) {
	int high = sum;
	while (low <= high) {
		int cnt = 0, tmp = 0;
		int mid = (low + high) / 2;
		for (int i = 0; i < N; i++) {
			if (tmp + arr[i] > mid) {
				tmp = 0;
				cnt += 1;
			}
			tmp += arr[i];
		}
		if (tmp != 0) cnt += 1;
		if (cnt <= M) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << low << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int low = -1, sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		low = max(low, arr[i]);
	}
	binarySearch(sum, low);
	return 0;
}