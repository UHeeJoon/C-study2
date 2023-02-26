#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr int way_row[] = { 0,1,0,-1 };
constexpr int way_col[] = { 1,0,-1,0 };
struct warrior
{
	int row;
	int col;
	int time_take_to_move;
};
int save_princess(const vector<vector<int>>& castle, const int start_row, const int start_col, const int castle_row, const int castle_col, const int cursing_time, const bool gram = false)
{
	vector<vector<bool>> visited(castle_row, vector<bool>(castle_col));
	queue<warrior> warrior_move;
	warrior_move.push({ start_row,start_col,0 });
	visited[start_row][start_col] = true;
	int move_count = 987654321;
	while (!warrior_move.empty())
	{
		const warrior current_state = warrior_move.front();
		warrior_move.pop();
		const int time_to_next_move = current_state.time_take_to_move + 1;
		if (time_to_next_move > cursing_time)
		{
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			const int next_row = current_state.row + way_row[i];
			const int next_col = current_state.col + way_col[i];
			if (next_row < 0 || next_row >= castle_row || next_col < 0 || next_col >= castle_col || visited[next_row][next_col]) {
				continue;
			}
			if (!gram && castle[next_row][next_col] == 1)
			{
				continue;
			}
			if (castle[next_row][next_col] == 2)
			{
				move_count = min(move_count, time_to_next_move + save_princess(castle, next_row, next_col, castle_row, castle_col, cursing_time, true));
			}
			if (next_row == castle_row - 1 && next_col == castle_col - 1)
			{
				move_count = min(move_count, time_to_next_move);
			}
			warrior_move.push({ next_row , next_col, time_to_next_move });
			visited[next_row][next_col] = true;
		}
	}

	return move_count > cursing_time ? 987654321 : move_count;
}
int main()
{
	FAST_IO;
	int castle_row, castle_col, cursing_time;
	cin >> castle_row >> castle_col >> cursing_time;
	vector<vector<int>>castle(castle_row, vector<int>(castle_col));
	for (vector<int>& row : castle)
	{
		for (int& element : row)
		{
			cin >> element;
		}
	}

	const int answer = save_princess(castle, 0, 0, castle_row, castle_col, cursing_time);
	if (answer == 987654321)
	{
		cout << "Fail\n";
	}
	else
	{
		cout << answer << '\n';
	}
	return 0;
}