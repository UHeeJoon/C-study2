#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int n; cin >> n;
	long long multi = 1;
	for (int i = 2; i <= n; i++)
	{
		multi *= i;
	}
	cout << multi << '\n';
	return 0;
}