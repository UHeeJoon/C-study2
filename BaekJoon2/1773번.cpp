#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool times[2'000'000];
int main()
{
	FAST_IO;
	int n, c; cin >> n >> c;
	while (n--)
	{
		int s; cin >> s;
		for (int i = s; i <= c; i += s)
		{
			if (times[i]) { continue; }
			times[i] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i <= c; i++)
	{
		if (times[i])
		{
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}