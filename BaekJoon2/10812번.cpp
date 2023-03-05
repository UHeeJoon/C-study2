#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	vector<int> arr(n);
	for (int i = 1; i <= n; i++)arr[i - 1] = i;
	while (m--)
	{
		int i, j, k; cin >> i >> j >> k;
		i -= 1; k -= 1;
		rotate(arr.begin() + i, arr.begin() + k, arr.begin() + j);
	}
	for (const int a : arr)
	{
		cout << a << ' ';
	}
	cout << '\n';
	return 0;
}