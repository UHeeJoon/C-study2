// 20165번 인내의 도미노 장인 호석...
// https://www.acmicpc.net/problem/20165
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
struct statement
{
	int row;
	int col;
	int size;
};
constexpr int d_row[] = { 0,0,1,-1 };
constexpr int d_col[] = { 1,-1,0,0 };
int select_direction(const int attack_direction)
{
	switch (attack_direction)
	{
	case 'E': return 0;
	case 'W': return 1;
	case 'S': return 2;
	case 'N': return 3;
	default:;
	}
	return -1; // error
}
void knock_over_dominoes(const vector<vector<int>>& board, const int board_row, const int board_col,
	vector<vector<char>>& board_state, const int attack_row, const int attack_col,
	const char attack_direction, int& score)
{
	board_state[attack_row][attack_col] = 'F';
	const int attack_d = select_direction(attack_direction);
	queue<statement> next_knock_over;
	next_knock_over.push({ attack_row, attack_col, board[attack_row][attack_col] - 1 });
	while (!next_knock_over.empty())
	{
		const statement current = next_knock_over.front();
		next_knock_over.pop();
		for (int i = 1; i <= current.size; i++)
		{
			const int next_row = current.row + d_row[attack_d] * i;
			const int next_col = current.col + d_col[attack_d] * i;
			if (next_row < 0 || next_row >= board_row || next_col < 0 || next_col >= board_col || board_state[next_row][next_col] == 'F') continue;
			next_knock_over.push({ next_row,next_col, board[next_row][next_col] - 1 });
			board_state[next_row][next_col] = 'F';
		}
		score++;
	}
}
void print_board_state(const vector<vector<char>>& board_state)
{
	for (const vector<char>& row : board_state)
	{
		for (const char element : row)
		{
			cout << element << ' ';
		}
		cout << '\n';
	}
}
int main()
{
	FAST_IO;
	int board_row, board_col, game_round;
	cin >> board_row >> board_col >> game_round;
	vector<vector<int>> board(board_row, vector<int>(board_col));
	vector<vector<char>> board_state(board_row, vector<char>(board_col, 'S'));
	for (vector<int>& row : board)
	{
		for (int& element : row)
		{
			cin >> element;
		}
	}
	int score = 0;
	while (game_round--)
	{
		int attack_row, attack_col;
		char attack_direction;
		cin >> attack_row >> attack_col >> attack_direction;
		knock_over_dominoes(board, board_row, board_col, board_state, attack_row - 1, attack_col - 1, attack_direction, score);
		int defender_row, defender_col;
		cin >> defender_row >> defender_col;
		board_state[defender_row - 1][defender_col - 1] = 'S';
	}
	cout << score << '\n';
	print_board_state(board_state);
	return 0;
}