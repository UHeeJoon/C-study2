#include<bits/stdc++.h>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX] = { 0, };
int arr2[MAX] = { 0, };
bool visited[MAX] = { 0, };
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[cnt] = arr2[i];
		dfs(cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr2[i];
	sort(arr2 + 0, arr2 + n + 1);
	dfs(0);
}