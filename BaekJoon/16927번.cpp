#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int arr[302][302];
int tmp_arr[302][302];
void rotate_y_x(int& y, int& x, const int y1, const int x1, const int y2, const int x2)
{
	if (y == y1 && x < x2)
	{
		x++;
	}
	else if (x == x2 && y < y2)
	{
		y++;
	}
	else if (y == y2 && x > x1)
	{
		x--;
	}
	else if (x == x1 && y > y1)
	{
		y--;
	}
}

void rotate(const int n, const int m, const int r)
{
	int cnt = 0;
	int nn = n, mm = m;
	while (true)
	{
		const int repeat_count = nn * 2 + (mm - 2) * 2;

		int tmp = r % repeat_count;
		if (tmp)
		{
			const int y1 = cnt, x1 = cnt, y2 = n - 1 - cnt, x2 = m - 1 - cnt;
			int y = cnt, x = cnt;
			while (tmp)
			{
				rotate_y_x(y, x, y1, x1, y2, x2);
				tmp--;
			}
			int dy = cnt, dx = cnt;
			for (int i = 0; i < repeat_count; i++)
			{

				arr[dy][dx] = tmp_arr[y][x];
				rotate_y_x(y, x, y1, x1, y2, x2);
				rotate_y_x(dy, dx, y1, x1, y2, x2);
			}
		}
		cnt++;
		nn -= 2; mm -= 2;
		if (nn <= 0 || mm <= 0)return;
	}
}
void print_array(const int n, const  int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	FAST_IO;
	int n, m, r; cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			tmp_arr[i][j] = arr[i][j];
		}
	}

	rotate(n, m, r);

	print_array(n, m);

	return 0;
}