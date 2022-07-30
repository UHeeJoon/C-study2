#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int n, m; cin >> n >> m;
		if (!n && !m)break;
		vector<int> v(n), v2(m);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		for (int i = 0; i < m; i++)
			cin >> v2[i];
		int i = 0, j = 0, cnt = 0;
		while (i < n && j < m) {
			if (v[i] < v2[j])i++;
			else if (v[i] > v2[j])j++;
			else {
				cnt++; i++; j++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}