#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	vector<vector<int>> cube(100, vector<int>(100));
	while (n--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		for (int i = y1; i <= y2; i++)
		{
			for (int j = x1; j <= x2; j++)
			{
				cube[i][j]++;
			}
		}
	}
	int count = 0;
	for (const vector<int>& row : cube)
	{
		for (const int element : row)
		{
			if (element > m)
			{
				count++;
			}
		}
	}
	cout << count << '\n';
	return 0;
}