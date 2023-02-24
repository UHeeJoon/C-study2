#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int check(const vector<int>& trophy)
{
	int count = 0;
	int max = 0;
	for (const int& a : trophy)
	{
		if (max < a)
		{
			max = a;
			count++;
		}
	}
	return count;
}
int main()
{
	FAST_IO;
	int n; cin >> n;
	vector<int> trophy(n);
	for (int& a : trophy)cin >> a;
	cout << check(trophy) << '\n';
	reverse(trophy.begin(), trophy.end());
	cout << check(trophy) << '\n';
	return 0;
}