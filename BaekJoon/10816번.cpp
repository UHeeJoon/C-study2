#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		auto l = lower_bound(v.begin(), v.end(), num);
		auto r = upper_bound(v.begin(), v.end(), num);
		cout << r - l << ' ';
	}
	cout << '\n';
	return 0;
}