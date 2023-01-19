#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define DURABILITY first
#define IS_EXIST second
void rotate_robot(vector<pair<int, bool>>& belt, const int belt_size)
{
	belt[belt_size / 2 - 1].IS_EXIST = false;
	for (int i = 0; i < belt_size; i++)
	{
		swap(belt[0], belt[i]);
	}
}
void move_robot(vector<pair<int, bool>>& belt, const int half_of_belt_size, int& zero_count)
{
	belt[half_of_belt_size].IS_EXIST = false;
	for (int i = half_of_belt_size - 1; i >= 0; i--)
	{
		if (belt[i].IS_EXIST && !belt[i + 1].IS_EXIST && belt[i + 1].DURABILITY)
		{
			belt[i + 1].DURABILITY -= 1;
			if (!belt[i + 1].DURABILITY) { zero_count += 1; }
			belt[i + 1].IS_EXIST = true;
			belt[i].IS_EXIST = false;
		}
	}
	if (belt[0].DURABILITY && !belt[0].IS_EXIST)
	{
		belt[0].DURABILITY -= 1;
		if (!belt[0].DURABILITY) { zero_count += 1; }
		belt[0].IS_EXIST = true;
	}
}
int main() {
	FAST_IO;
	int n, k;
	cin >> n >> k;
	const int belt_size = 2 * n;
	vector<pair<int, bool>>belt(belt_size);
	for (int i = 0; i < belt_size; i++)
	{
		cin >> belt[i].DURABILITY;
	}
	int robot_move_count = 0;
	int zero_count = 0;
	while (zero_count < k)
	{
		rotate_robot(belt, belt_size);
		move_robot(belt, belt_size / 2 - 1, zero_count);
		robot_move_count++;
	}
	cout << robot_move_count << '\n';
	return 0;
}