#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr int dr[] = { 0,1,0,-1 };
constexpr int dc[] = { 1,0,-1,0 };
void print_state(const vector<vector<char>>& pasture)
{
	for (const vector<char>& row : pasture)
	{
		for (const char& element : row)
		{
			cout << element;
		}
		cout << '\n';
	}
}
void fence_installation(vector<vector<char>>& pasture, const vector<pair<int, int>>& wolves, const int r, const int c)
{
	for (const pair<int, int> wolf : wolves)
	{
		for (int i = 0; i < 4; i++)
		{
			const int nr = dr[i] + wolf.first;
			const int nc = dc[i] + wolf.second;
			if (nr < 0 || nr >= r || nc < 0 || nc >= c || pasture[nr][nc] == 'D' || pasture[nr][nc] == 'W')continue;
			if (pasture[nr][nc] == 'S')
			{
				cout << 0 << '\n';
				return;
			}
			pasture[nr][nc] = 'D';
		}
	}
	cout << 1 << '\n';
	print_state(pasture);
}
int main()
{
	FAST_IO;
	int r, c; cin >> r >> c;
	vector<vector<char>> pasture(r, vector<char>(c));
	vector<pair<int, int>> wolves;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> pasture[i][j];
			if (pasture[i][j] == 'W')
			{
				wolves.emplace_back(i, j);
			}
		}
	}
	fence_installation(pasture, wolves, r, c);
	return 0;
}