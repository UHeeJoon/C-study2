#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool check(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return true;
		}
	}
	return false;
}
void back_tracking(const int n, const int idx, const int num)
{
	if (n <= idx)
	{
		cout << num << '\n';
		return;
	}
	for (int i = 1; i < 10; i += 2)
	{
		const int tmp = num * 10 + i;
		if (check(tmp)) { continue; }
		back_tracking(n, idx + 1, tmp);
	}
}
int main()
{
	FAST_IO;
	int n; cin >> n;
	for (const int num : {2, 3, 5, 7})
	{
		back_tracking(n, 1, num);
	}
	return 0;
}