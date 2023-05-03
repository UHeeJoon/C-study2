#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int num[1037];
int main()
{
	FAST_IO;
	int idx = 0;
	for (int i = 1; i <= 45; i++)
	{
		for (int j = 0; j < i; j++)
		{
			num[++idx] = i;
		}
	}
	int a, b;
	cin >> a >> b;
	int sum = 0;
	for (; a <= b; a++)
	{
		sum += num[a];
	}
	cout << sum << '\n';
	return 0;
}