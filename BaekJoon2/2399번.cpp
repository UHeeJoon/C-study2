#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n; cin >> n;
	vector<int> num(n);
	for (int& element : num)
	{
		cin >> element;
	}
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)continue;
			sum += abs(num[i] - num[j]);
		}
	}
	cout << sum << '\n';
	return 0;
}