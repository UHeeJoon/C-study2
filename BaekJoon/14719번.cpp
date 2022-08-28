#include<bits/stdc++.h>
using namespace std;
#define MAX 510
#define INF 2147483647
int n, m;
int arr[MAX] = { 0, };
int searchLeft(int idx) {
	if (idx == 0)return 0;
	return max(arr[idx], searchLeft(idx - 1));
}
int searchRight(int idx) {
	if (idx == m + 1)return 0;
	return max(arr[idx], searchRight(idx + 1));
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> arr[i];
	int ans = 0;
	for (int i = 2; i < m; i++) {
		ans += max(0, min(searchLeft(i - 1), searchRight(i + 1)) - arr[i]);
		//cout << searchLeft(i - 1) << ' ' << searchRight(i + 1) << ' ' << arr[i] << '\n';
	}
	cout << ans << '\n';
	return 0;
}
