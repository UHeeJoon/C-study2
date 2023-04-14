#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int a, b, c, m; cin >> a >> b >> c >> m;
	int sum = 0, tired = 0, _time = 0;
	while (tired <= m && _time++ < 24)
	{
		if (tired + a <= m)
		{
			tired += a;
			sum += b;
		}
		else
		{
			tired = tired - c < 0 ? 0 : tired - c;
		}
	}
	cout << sum << '\n';
	return 0;
}