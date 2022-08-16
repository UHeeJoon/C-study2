#include<bits/stdc++.h>
using namespace std;
void check(int now, bool visited[], int arr[]) {
	if (visited[now])return;
	visited[now] = true;
	check(arr[now], visited, arr);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int arr[1010] = { 0, };
		bool visited[1010] = { 0, };
		int cnt = 0;
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				check(arr[i], visited, arr);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}