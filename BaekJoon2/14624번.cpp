#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n; cin >> n;
	if (n & 1)
	{
		for (int i = 0; i < n; i++) { cout << "*"; }
		cout << '\n';
		int idx = (n - 1) / 2;
		while (idx >= 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (i == (n - idx)) { break; }
				cout << ((i == idx || i == (n - idx - 1)) ? "*" : " ");
			}
			cout << "\n";
			idx--;
		}
		return 0;
	}
	cout << "I LOVE CBNU\n";
	return 0;
}