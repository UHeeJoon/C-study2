#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr int dy[] = { 0,1,0,-1 };
constexpr int dx[] = { 1,0,-1,0 };
void bfs(vector<vector<char>>& grass, int y, int x)
{
	const int r = static_cast<int>(grass.size());
	const int c = static_cast<int>(grass[0].size());
	queue<pair<int, int>> q;
	q.emplace(y, x);
	while (!q.empty())
	{
		const int ny = q.front().first;
		const int nx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			const int yy = ny + dy[i];
			const int xx = nx + dx[i];
			if (yy < 0 || yy >= r || xx < 0 || xx >= c || grass[yy][xx] == '.') { continue; }
			grass[yy][xx] = '.';
			q.emplace(yy, xx);
		}
	}
}
int main()
{
	FAST_IO;
	int r, c; cin >> r >> c;
	vector<vector<char>> grass(r, vector<char>(c, '.'));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char ch; cin >> ch;
			if (ch != '.')
			{
				grass[i][j] = ch;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (grass[i][j] != '.')
			{
				bfs(grass, i, j);
				count++;
			}
		}
	}
	cout << count << '\n';
	return 0;
}