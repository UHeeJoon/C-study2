#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)v[i] = i + 1;
	while (m--)
	{
		int i, j; cin >> i >> j;
		reverse(v.begin() + i - 1, v.begin() + j);
	}
	for (const int a : v) cout << a << ' ';
	cout << '\n';
	return 0;
}