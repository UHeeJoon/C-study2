#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main()
{
	FAST_IO;
	int n, l; cin >> n >> l;
	vector<int> v(n + l, 0);
	int ans = 0, count = 0;
	for (int i = l; i < n + l; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
		int sum = v[i] - v[i - l];
		if (129 <= sum && sum <= 138) {
			ans = max(ans, ++count);
		}
		else {
			count = 0;
		}
	}
	cout << ans << '\n';
	return 0;
}