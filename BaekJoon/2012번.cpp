#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main()
{
	FAST_IO;
	int n; cin >> n;
	vector<int>v(n);
	for (int& el : v) {
		cin >> el;
	}
	sort(v.begin(), v.end());
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += v[i - 1] - i < 0 ? -(v[i - 1] - i) : 0;
	}
	cout << sum << '\n';
	return 0;
}