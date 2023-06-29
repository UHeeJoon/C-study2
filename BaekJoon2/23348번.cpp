#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int a, b, c; cin >> a >> b >> c;
	int n; cin >> n;
	int _max = -987654321;
	while (n--)
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			int a2, b2, c2; cin >> a2 >> b2 >> c2;
			sum += (a * a2 + b * b2 + c * c2);
		}
		_max = max(sum, _max);
	}
	cout << _max << '\n';
	return 0;
}