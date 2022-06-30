#include<bits/stdc++.h>
using namespace std;
int arr[10];
int arr2[10];
int n, m;
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr2[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = idx; i < n; i++) {
		if (tmp != arr[i]) {
			tmp = arr[i];
			arr2[cnt] = arr[i];
			dfs(i, cnt + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	dfs(0, 0);
	return 0;
}