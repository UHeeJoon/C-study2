//#pragma warning(disable : 4996)
//3967번 풀이중...
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool alpha[13];
void calculation(char magic_star[][10])
{
}
bool check(const pair<int, int> x)
{
	int sum = 0;
	if(x.first == 0)
	{
		
	}
}
void back_tracking(char magic_star[][10], const int x_index, vector<pair<int, int>>& x)
{
	if(x_index == static_cast<int>(x.size()))
	{
		calculation(magic_star);
		return;
	}
	for (int j = 0; j < 12; j++)
	{
		if(!alpha[j])
		{
			const char tmp = magic_star[x[x_index].first][x[x_index].second];
			alpha[j] = true;
			magic_star[x[x_index].first][x[x_index].second] = static_cast<char>(j + 'A');
			if (check(x[x_index])) {
				magic_star[x[x_index].first][x[x_index].second] = tmp;
				alpha[j] = false;
				return;
			}
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
	cout << _count << '\n';
	return 0;
}