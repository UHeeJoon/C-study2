#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr char INPUT_ERROR = '?';
char changeReg(const char c)
{
	switch (c)
	{
	case '.': return '.';
	case 'O': return 'O';
	case '-': return '|';
	case '|': return '-';
	case '/': return '\\';
	case '\\': return '/';
	case '^': return '<';
	case '<': return 'v';
	case 'v': return '>';
	case '>': return '^';
	default:return INPUT_ERROR;
	}
}
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	vector<vector<char>> img(n, vector<char>(m + 1, '.'));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c; cin >> c;
			if (c != '.') img[i][j] = c;
		}
	}
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			cout << changeReg(img[j][i]);
		}
		cout << '\n';
	}
	return 0;
}