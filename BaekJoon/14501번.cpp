#include<bits/stdc++.h>
using namespace std;
int t, _max;
pair<int, int> p[17];
void Dp(int n, int sum) {
	if (n == t + 1) {
		_max = max(_max, sum);
		return;
	}
	if (n > t + 1)
		return;
	Dp(n + 1, sum);
	Dp(n + p[n].first, sum + p[n].second);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> p[i].first >> p[i].second;
	}
	Dp(1, 0);
	cout << _max << '\n';
	return 0;
}