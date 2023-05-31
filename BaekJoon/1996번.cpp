#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr int dy[] = { 0,1,0,-1,1,1,-1,-1 };
constexpr int dx[] = { 1,0,-1,0,1,-1,1,-1 };
void cal(vector<vector<char>>& _map, const int i, const int j, const int count)
{
	const int len = static_cast<int>(_map.size());
	for (int k = 0; k < 8; k++)
	{
		const int ny = i + dy[k];
		const int nx = j + dx[k];
		if (ny < 0 || ny >= len || nx < 0 || nx >= len || _map[ny][nx] == '*' || _map[ny][nx] == 'M') { continue; }
		const char num = static_cast<char>(_map[ny][nx] + count);
		_map[ny][nx] = num > '9' ? 'M' : num;
	}
}
int main()
{
	FAST_IO;
	int n; cin >> n;
	vector<vector<char>> _map(n, vector<char>(n, '0'));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			if (c != '.')
			{
				cal(_map, i, j, c - '0');
				_map[i][j] = '*';
			}
		}
	}
	for (const vector<char>& row : _map)
	{
		for (const char element : row)
		{
			cout << element;
		}
		cout << '\n';
	}
	return 0;
}