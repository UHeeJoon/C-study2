#include<bits/stdc++.h>
using namespace std;
int n, _max, arr[10], arr2[10];
bool visited[10];
void dfs(int cnt) {
	int sum = 0;
	if (cnt == n) {
		for (int i = 0; i < n - 1; i++) {
			sum += abs(arr[i] - arr[i + 1]);
		}
		_max = max(sum, _max);
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = arr2[i];
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	dfs(0);
	cout << _max << '\n';
	return 0;
}