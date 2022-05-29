#include<bits/stdc++.h>
using namespace std;
int student[3][7];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int s, y; cin >> s >> y;
		student[s][y]++;
	}
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			if (student[i][j] == 0) continue;
			cnt += student[i][j] % k == 0 ? student[i][j] / k : student[i][j] / k + 1;
		}
	}
	cout << cnt << '\n';
	return 0;
}