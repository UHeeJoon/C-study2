#include<bits/stdc++.h>
using namespace std;
int arr[1001][6];
bool check[1001][1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[j][i] == arr[k][i])
					check[j][k] = check[k][j] = true;
			}
		}
	}
	int ans = -1;
	int count = -1;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			if (check[i][j])tmp++;
		}
		if (tmp > count) {
			ans = i + 1;
			count = tmp;
		}
	}
	cout << ans << '\n';
	return 0;
}