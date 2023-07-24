#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int a, b; cin >> a >> b;
	map<int, bool> _map;
	for (int i = 0; i < a; i++)
	{
		int num; cin >> num;
		_map[num] = true;
	}
	while (b--)
	{
		int num; cin >> num;
		if (_map[num])
		{
			a--;
		}
		_map[num] = false;
	}
	cout << a << '\n';
	for (const auto tmp : _map)
	{
		if (tmp.second)
		{
			cout << tmp.first << ' ';
		}
	}
	return 0;
}