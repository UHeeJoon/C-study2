#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int k; cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << '1';
	}
	for (int i = 0; i < k - 1; i++)
	{
		cout << '0';
	}
	cout << '\n';
	return 0;
}