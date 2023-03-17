#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int r, c; cin >> r >> c;
	int a, b; cin >> a >> b;
	for (int i = 0; i < r; i++)
	{
		for (int m = 0; m < a; m++)
		{
			char chess = 'X';
			if (i & 1)
			{
				chess = '.';
			}
			for (int j = 0; j < c; j++)
			{

				for (int n = 0; n < b; n++)
				{
					cout << chess;
				}
				chess = chess == '.' ? 'X' : '.';
			}
			cout << '\n';
		}
	}
	return 0;
}