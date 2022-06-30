#include<bits/stdc++.h>
using namespace std;
int arr[10];
int arr2[10];
bool visited[10];
int n, m;
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr2[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && tmp != arr[i]) {
			visited[i] = true;
			tmp = arr[i];
			arr2[cnt] = arr[i];
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	dfs(0);
	return 0;
}