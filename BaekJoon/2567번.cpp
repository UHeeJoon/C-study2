#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int drawing_paper[105][105];
void search(const int y, const int x, int& area)
{
	for (const pair<int, int> way : { make_pair(1,0), make_pair(0,1) , make_pair(-1,0) , make_pair(0,-1) })
	{
		const int ny = y + way.first;
		const int nx = x + way.second;
		if (ny < 1 || ny > 100 || nx < 1 || nx > 100 || drawing_paper[ny][nx] == 0)continue;
		drawing_paper[ny][nx] = 2;
		area++;
	}
}
int main() {
	FAST_IO;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
			{
				if (!drawing_paper[j][k]) drawing_paper[j][k] = 1;
			}
		}
	}
	int area = 0;
	for (int i = 0; i <= 101; i++)
	{
		for (int j = 0; j <= 101; j++)
		{
			if (!drawing_paper[i][j])
			{
				search(i, j, area);
			}
		}
	}
	cout << area << '\n';
	return 0;
}