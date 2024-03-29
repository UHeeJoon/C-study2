#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr int moving[9][2] = { {0,0}, {0,-1}, {-1,-1},{-1,0},{-1,1},{0,1},{1, 1},{1,0},{1,-1} };
struct cloud
{
	void location_clearance(const int basket_size)
	{
		y = (y >= basket_size ? y % basket_size : y < 0 ? (basket_size * 30 + y) % basket_size : y);
		x = (x >= basket_size ? x % basket_size : x < 0 ? (basket_size * 30 + x) % basket_size : x);
	}
	int y;
	int x;
};

void clouds_initialize(vector<cloud>& clouds, const int basket_size)
{
	clouds.push_back({ basket_size - 1, 0 });
	clouds.push_back({ basket_size - 1, 1 });
	clouds.push_back({ basket_size - 2, 0 });
	clouds.push_back({ basket_size - 2, 1 });
}

bool check_area(const int basket_size, const int y, const int x)
{
	return y < 0 || y >= basket_size || x < 0 || x >= basket_size;
}

void make_clouds(vector<vector<int>>& baskets, vector<cloud>& clouds, vector<vector<bool>>& clouds_location, const int basket_size)
{
	for (int i = 0; i < basket_size; i++)
	{
		for (int j = 0; j < basket_size; j++)
		{
			if (clouds_location[i][j])
			{
				clouds_location[i][j] = false;
				continue;
			}
			if (baskets[i][j] > 1)
			{
				clouds.push_back({ i, j });
				baskets[i][j] -= 2;
				clouds_location[i][j] = true;
			}
		}
	}
}

void water_copy_burg(vector<vector<int>>& baskets, const vector<cloud>& clouds, const int basket_size)
{
	vector<vector<int>> copy_baskets(baskets);
	for (const cloud cloud : clouds)
	{
		for (int i = 2; i <= 8; i += 2)
		{
			const int y = cloud.y + moving[i][0];
			const int x = cloud.x + moving[i][1];
			if (check_area(basket_size, y, x) || baskets[y][x] == 0)
			{
				continue;
			}
			copy_baskets[cloud.y][cloud.x]++;
		}
	}
	baskets.swap(copy_baskets);
}

void move_clouds(vector<vector<int>>& baskets, vector<cloud>& clouds, vector<vector<bool>>& clouds_location, const int basket_size, const int move_direction, const int move_squares)
{
	for (cloud& cloud : clouds)
	{
		cloud.y += (moving[move_direction][0]) * move_squares;
		cloud.x += (moving[move_direction][1]) * move_squares;
		cloud.location_clearance(basket_size);
		baskets[cloud.y][cloud.x]++;
		clouds_location[cloud.y][cloud.x] = true;
	}
}

void wising_rain(vector<vector<int>>& baskets, const int basket_size, int move_command_size)
{
	vector<cloud> clouds;
	clouds_initialize(clouds, basket_size);
	while (move_command_size--)
	{
		vector<vector<bool>> clouds_location(basket_size, vector<bool>(basket_size));
		int move_direction, move_squares;
		cin >> move_direction >> move_squares;

		move_clouds(baskets, clouds, clouds_location, basket_size, move_direction, move_squares);
		water_copy_burg(baskets, clouds, basket_size);
		vector<cloud>().swap(clouds); // free
		make_clouds(baskets, clouds, clouds_location, basket_size);
	}
}

int print_water_sum(const vector<vector<int>>& baskets, const int basket_size)
{
	int sum = 0;
	for (int i = 0; i < basket_size; i++)
	{
		for (int j = 0; j < basket_size; j++)
		{
			sum += baskets[i][j];
		}
	}
	return sum;
}

int main() {
	FAST_IO;
	int basket_size, move_command_size;
	cin >> basket_size >> move_command_size;
	vector<vector<int>> baskets(basket_size, vector<int>(basket_size));
	for (int i = 0; i < basket_size; i++)
	{
		for (int j = 0; j < basket_size; j++)
		{
			cin >> baskets[i][j];
		}
	}
	wising_rain(baskets, basket_size, move_command_size);
	cout << print_water_sum(baskets, basket_size) << '\n';
	return 0;
}