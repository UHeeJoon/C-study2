#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 100'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> v;
	while (m--) {
		int a, b; cin >> a >> b;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), [](int a, int b) {
		return a > b;
	});
	int cnt(0);
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] < n) {
			cnt += (n - v[i]);
		}
	}
	cout << cnt << '\n';
	return 0;
}