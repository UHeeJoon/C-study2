#include<bits/stdc++.h>
using namespace std;
int land[501][501];
int _max, _min = 987654321;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, b; cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> land[i][j];
			_min = min(_min, land[i][j]);
			_max = max(_max, land[i][j]);
		}
	}
	int cnt = 987654321, height = 0;
	for (int i = _min; i <= _max; i++) {
		int build(0), remove(0), tmp;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				tmp = i - land[j][k];
				if (tmp < 0)
					remove += tmp * -1;
				else
					build += tmp;
			}
		}
		if (build <= remove + b) {
			tmp = build + remove * 2;
			if (cnt > tmp)
				cnt = tmp, height = i;
			if (tmp == cnt)
				if (height < i)
					height = i;
		}
	}
	cout << cnt << ' ' << height << '\n';
	return 0;
}