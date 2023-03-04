#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	if (n & 1 && m & 1)
	{
		cout << n * m - 1 << '\n';
	}
	else
	{
		cout << n * m << '\n';
	}
	return 0;
}