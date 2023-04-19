#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int r, c, zr, zc;
	char datas[52][52] = { {0}, };
	cin >> r >> c >> zr >> zc;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> datas[i][j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int rr = 0; rr < zr; rr++)
		{
			for (int j = 0; j < c; j++)
			{
				for (int cc = 0; cc < zc; cc++)
				{
					cout << datas[i][j];
				}
			}
			cout << '\n';

		}
	}

	return 0;
}