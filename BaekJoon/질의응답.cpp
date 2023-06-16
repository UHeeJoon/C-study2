//#pragma warning(disable : 4996)
//https://www.acmicpc.net/problem/1996
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n, l, time = 1;
	cin >> n >> l;
	vector<vector<int>> v(n, vector<int>(3));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= l; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == v[j][0] && v[j][1] > time % (v[j][1] + v[j][2]))
			{
				time += v[j][1] - time % (v[j][1] + v[j][2]);
			}
		}
		time++;
	}
	cout << time - 1 << '\n';
	return 0;
}
