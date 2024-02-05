#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n, k; cin >> n >> k;
	vector<int> v(n * 2 + 10, 0);
	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		v[i] = v[i + n] = num;
	}
	int _max = -987654321;
	for (int i = 1; i <= n * 2; i++) {
		v[i] = v[i - 1] + v[i];
		if (i >= k) {
			_max = max(_max, v[i] - v[i - k]);
		}
	}
	cout << _max << '\n';
	return 0;
}