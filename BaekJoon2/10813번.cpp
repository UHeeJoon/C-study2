#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	vector<int> basket(n + 1);
	for (int i = 1; i <= n; i++)basket[i] = i;
	while (m--)
	{
		int i, j; cin >> i >> j;
		swap(basket[i], basket[j]);
	}
	for (int i = 1; i <= n; i++)cout << basket[i] << ' ';
	cout << '\n';
	return 0;
}