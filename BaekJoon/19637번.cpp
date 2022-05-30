#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, string>> v;
void binarySearch(int a) {
	int l = 0;
	int r = n;
	int mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (v[mid].first < a)
			l = mid + 1;
		else
			r = mid - 1;
	}
	if (a > v[mid].first)
		cout << v[mid + 1].second << '\n';
	else
		cout << v[mid].second << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; string s; cin >> s >> a;
		v.push_back({ a,s });
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		binarySearch(a);
	}
	return 0;
}