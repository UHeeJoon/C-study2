#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool isPrime[1'000'002];
vector<int> prime;
int main()
{
	FAST_IO;
	for (int i = 2; i <= 1'000'001; i++)
	{
		if (isPrime[i]) { continue; }
		for (int j = i + i; j <= 1'000'000; j += i)
		{
			isPrime[j] = true;
		}
		prime.push_back(i);
	}
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int count = 0;
		for (const int num : prime)
		{
			if (num > n / 2) { break; }
			if (!isPrime[n - num])
			{
				count++;
			}
		}
		cout << count << '\n';
	}
	return 0;
}