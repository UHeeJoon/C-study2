#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int tc; cin >> tc;
	while (tc--)
	{
		int a, b, x; cin >> a >> b >> x;
		cout << a * (x - 1) + b << '\n';
	}
	return 0;
}
