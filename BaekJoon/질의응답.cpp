#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef unsigned long long ull;
//typedef long long ll;
int c, r, k;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> r >> k;
	const int mul = c * r;
	if (mul < k)
	{
		cout << 0 << '\n';
		return 0;
	}
	if(k==1)
	{
		cout << 1 << ' ' << 1 << '\n';
		return 0;
	}
	int count = 1, i = 1, j = 1;
	int dist = 1;
	bool flag = false;
	while (count <= mul)
	{
		for(int a = 1;a < r;a++)
		{
			i += dist;
			count++;
			if(count == k)
			{
				cout << j << ' ' << i << '\n';
				return 0;
			}
		}
		if (flag)
			r--;
		else flag = true;
		for(int b = 1;b <c;b++)
		{
			j += dist;
			count++;
			if (count == k)
			{
				cout << j << ' ' << i << '\n';
				return 0;
			}
		}
		c--;
		dist = -dist;
	}
	return 0;
}
