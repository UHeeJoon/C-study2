#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int move(vector<vector<int>>& boxes, int y, const int x, const int height)
{
	int count = 0;
	while (y + 1 < height && !boxes[y + 1][x])
	{
		swap(boxes[y][x], boxes[y + 1][x]);
		y++;
		count++;
	}
	return count;
}
int main()
{
	FAST_IO;
	int tc; cin >> tc;
	while (tc--)
	{
		int width, height; cin >> height >> width;
		vector<vector<int>>	boxes(height, vector<int>(width));
		for (vector<int>& row : boxes)
		{
			for (int& element : row)
			{
				cin >> element;
			}
		}
		int ans = 0;
		for (int i = height - 2; i >= 0; i--)
		{
			for (int j = 0; j < width; j++)
			{
				if (boxes[i][j])
					ans += move(boxes, i, j, height);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}