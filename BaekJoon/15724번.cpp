#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
			v[i][j] = v[i][j] + v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
		}
	}
	int k; cin >> k;
	while (k--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << v[x2][y2] - v[x2][y1 - 1] - v[x1 - 1][y2] + v[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}