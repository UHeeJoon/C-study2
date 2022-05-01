#include<bits/stdc++.h>
using namespace std;
int arr[10], n;
bool visited[10];
void dfs(int cnt) {
	if (cnt == n + 1) {
		for (int i = 1; i <= n; i++) {
			cout << arr[i] << ' '; 
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dfs(1);
	return 0;
}