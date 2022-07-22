#include<bits/stdc++.h>
using namespace std;
vector<int> v, v2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}
	sort(v.begin(), v.end()); sort(v2.begin(), v2.end());
	int i = 0, j = 0;
	while (i + j < n + m) {
		if (i == n)
			cout << v2[j++] << ' ';
		else if (j == m)
			cout << v[i++] << ' ';
		else {
			if (v[i] < v2[j])
				cout << v[i++] << ' ';
			else
				cout << v2[j++] << ' ';
		}
	}
	cout << '\n';
	return 0;
}