#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	for (int i = (int)v.size() - 1; i > 0; i--) {
		if (v[i] > v[i - 1])continue;
		else {
			int tmp = v[i - 1] - v[i] + 1;
			cnt += tmp;
			v[i - 1] = v[i - 1] - tmp;
		}
	}
	cout << cnt << '\n';
	return 0;
}