#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int arr[200001];
int n, m;
void binarySearch() {
	int high = 0, low = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (high) {
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
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	binarySearch();
	return 0;
}
