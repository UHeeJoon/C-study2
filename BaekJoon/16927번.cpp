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
	int starting_point = 0;
	int nn = n, mm = m;
	while (nn && mm)
	{
		const int border_length = nn * 2 + (mm - 2) * 2;

		int tmp = r % border_length;
		if (tmp)
		{
			int y = starting_point, x = starting_point;
			while (tmp)
			{
				rotate_y_x(y, x, starting_point, starting_point, n - 1 - starting_point, m - 1 - starting_point);
				tmp--;
			}
			int dy = starting_point, dx = starting_point;
			for (int i = 0; i < border_length; i++)
			{

				arr[dy][dx] = tmp_arr[y][x];
				rotate_y_x(y, x, starting_point, starting_point, n - 1 - starting_point, m - 1 - starting_point);
				rotate_y_x(dy, dx, starting_point, starting_point, n - 1 - starting_point, m - 1 - starting_point);
			}
		}
		starting_point++;
		nn -= 2; mm -= 2;
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



/*
 * 다른 사람 풀이
 #include<cstdio>
#include<algorithm>
int n, m, r;
int a[301][301];

void printary()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void rotate(int x, int y, int w, int h)
{
	int tmp = a[x][y];
	for(int i=y; i<y+w; i++)
	{
		a[x][i] = a[x][i+1];
	}
	for(int i=x; i<x+h; i++)
	{
		a[i][y+w-1] = a[i+1][y+w-1];
	}
	for(int i=y+w-1; i>y; i--)
	{
		a[x+h-1][i] = a[x+h-1][i-1];
	}
	for(int i=x+h-1; i>x; i--)
	{
		a[i][y] = a[i-1][y];
	}
	a[x+1][y] = tmp;
}

int main()
{
	scanf("%d %d %d", &n, &m, &r);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=0; i<std::min(n, m)/2; i++)
	{
		int w = m-2*i;
		int h = n-2*i;
		int rot = r % (w*h-((w-2)*(h-2)));
		for(int j=0; j<rot; j++)
		{
			rotate(i, i, w, h);
			
		}
	}
	printary();
}
 */