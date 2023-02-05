#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool alpha[13];
int search_slash(char magic_star[][10], const int r, const int c, const bool is_back = false)
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int tmp = 0;
		if (is_back && magic_star[r + i][c - i] != 'x')
		{
			tmp = (magic_star[r + i][c - i] - 'A') + 1;
		}
		else if (!is_back && magic_star[r + i][c + i] != 'x')
		{
			tmp = (magic_star[r + i][c + i] - 'A') + 1;
		}
		sum += tmp;
	}
	return sum;
}
int search_width(char magic_star[][10], const int r)
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		if (magic_star[r][i] == '.' || magic_star[r][i] == 'x') continue;
		sum += (magic_star[r][i] - 'A') + 1;
	}
	return sum;
}
bool check(char magic_star[][10])
{
	if (search_slash(magic_star, 1, 1) == 26 && search_slash(magic_star, 0, 4) == 26
		&& search_slash(magic_star, 0, 4, true) == 26 && search_slash(magic_star, 1, 7, true) == 26
		&& search_width(magic_star, 1) == 26 && search_width(magic_star, 3) == 26)
	{
		return true;
	}
	return false;
}
void calculation(char magic_star[][10])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << magic_star[i][j];
		}
		cout << '\n';
	}
}
void back_tracking(char magic_star[][10], const int x_index, vector<pair<int, int>>& x)
{
	if (check(magic_star))
	{
		calculation(magic_star);
		exit(0);
	}
	for (int j = 0; j < 12; j++)
	{
		if (!alpha[j])
		{
			alpha[j] = true;
			magic_star[x[x_index].first][x[x_index].second] = static_cast<char>(j + 'A');
			back_tracking(magic_star, x_index + 1, x);
			alpha[j] = false;
		}
	}
}
int main() {
	FAST_IO;
	char magic_star[6][10] = {};
	vector<pair<int, int>> x;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> magic_star[i][j];
			if (magic_star[i][j] == 'x')
			{
				x.emplace_back(i, j);
			}
			else if (magic_star[i][j] != '.')
			{
				alpha[magic_star[i][j] - 'A'] = true;
			}
		}
	}
	back_tracking(magic_star, 0, x);
	return 0;
}