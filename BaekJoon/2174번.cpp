#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
struct robot
{
	int x;
	int y;
	int side;
};
constexpr int dx[4] = { 0,1,0,-1 };
constexpr int dy[4] = { 1,0,-1,0 };
string move(vector<vector<int>>& ground, vector<robot>& robots, const int a, const int b, const int robot_num, const char order, int repeat_count)
{
	if (order == 'F')
	{
		while (repeat_count--)
		{
			const int nx = robots[robot_num].x + dx[robots[robot_num].side];
			const int ny = robots[robot_num].y + dy[robots[robot_num].side];
			if (nx < 1 || nx > a || ny < 1 || ny > b)
			{
				return "Robot " + to_string(robot_num) + " crashes into the wall";
			}
			if (ground[nx][ny])
			{
				return "Robot " + to_string(robot_num) + " crashes into robot " + to_string(ground[nx][ny]);
			}
			ground[nx][ny] = robot_num;
			ground[robots[robot_num].x][robots[robot_num].y] = 0;
			robots[robot_num].x += dx[robots[robot_num].side];
			robots[robot_num].y += dy[robots[robot_num].side];
		}
	}
	else if (order == 'L')
	{
		robots[robot_num].side = (robots[robot_num].side + 4 - repeat_count % 4) % 4;
	}
	else if (order == 'R')
	{
		robots[robot_num].side = (robots[robot_num].side + repeat_count % 4) % 4;
	}
	return "OK";
}
int main() {
	FAST_IO;
	int a, b; cin >> a >> b;
	int n, m; cin >> n >> m;
	vector<robot> robots(n + 1);
	vector<vector<int>> ground(a + 1, vector<int>(b + 1));
	for (int i = 1; i <= n; i++)
	{
		char side;
		cin >> robots[i].x >> robots[i].y >> side;
		if (side == 'N') robots[i].side = 0;
		else if (side == 'E') robots[i].side = 1;
		else if (side == 'S') robots[i].side = 2;
		else robots[i].side = 3;
		ground[robots[i].x][robots[i].y] = i;
	}
	string error_msg = "OK";
	while (m--)
	{
		int robot_num, repeat_count;
		char order;
		cin >> robot_num >> order >> repeat_count;
		if (error_msg == "OK")
		{
			error_msg = move(ground, robots, a, b, robot_num, order, repeat_count);
		}
	}
	cout << error_msg << '\n';
	return 0;
}