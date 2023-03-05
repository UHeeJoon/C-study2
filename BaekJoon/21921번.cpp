#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int x, n; cin >> x >> n;
	int max = 0, count = 1;
	int sum = 0;
	vector<int> num(x);
	for (int i = 0; i < x; i++)
	{
		cin >> num[i];
		sum += num[i];
		if (i >= n)
		{
			sum -= num[i - n];
		}
		if (max < sum)
		{
			max = sum;
			count = 1;
		}
		else if (max == sum)
		{
			count++;
		}
	}
	if (max == 0)
	{
		cout << "SAD\n";
	}
	else
	{
		cout << max << '\n' << count << '\n';
	}
	return 0;
}