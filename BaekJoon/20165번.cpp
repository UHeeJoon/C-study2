// 20165번 인내의 도미노 장인 호석...
// https://www.acmicpc.net/problem/20165
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
// State of overthrow the dominoes
struct statement
{
	int row;
	int col;
	int size;
};
// Direction : E, W, S, N
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

void overthrow_the_dominoes(const vector<vector<int>>& board, const int board_row, const int board_col,
	vector<vector<char>>& board_state, const int attack_row, const int attack_col,
	const char direction, int& score)
{
	// default value
	board_state[attack_row][attack_col] = 'F';
	const int attack_direction = select_direction(direction);

	// Variable(queue): for storing the next state
	queue<statement> next_knock_over;
	// initialize
	next_knock_over.push({ attack_row, attack_col, board[attack_row][attack_col] - 1 });

	// until everything overthrow
	while (!next_knock_over.empty())
	{
		const statement current = next_knock_over.front();
		next_knock_over.pop();

		for (int i = 1; i <= current.size; i++)
		{
			// next overthrow statement
			const int next_row = current.row + d_row[attack_direction] * i;
			const int next_col = current.col + d_col[attack_direction] * i;

			// condition check
			if (next_row < 0 || next_row >= board_row || next_col < 0 || next_col >= board_col || board_state[next_row][next_col] == 'F')
			{
				continue;
			} // condition passed

			// next overthrow domino
			next_knock_over.push({ next_row,next_col, board[next_row][next_col] - 1 });
			// overthrow statement
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
	// initialize
	int board_row, board_col, game_round;
	cin >> board_row >> board_col >> game_round;
	vector<vector<int>> board(board_row, vector<int>(board_col));
	vector<vector<char>> board_state(board_row, vector<char>(board_col, 'S'));
	// input
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
		// attack
		int attack_row, attack_col;
		char attack_direction;
		cin >> attack_row >> attack_col >> attack_direction;
		overthrow_the_dominoes(board, board_row, board_col, board_state, attack_row - 1, attack_col - 1, attack_direction, score);
		// defend
		int defender_row, defender_col;
		cin >> defender_row >> defender_col;
		board_state[defender_row - 1][defender_col - 1] = 'S';
	}
	// print answer
	cout << score << '\n';
	print_board_state(board_state);
	return 0;
}




/*
 #include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

int n, m, R, ans;
int a[105][105], backup[105][105];

void input() {
    cin >> n >> m >> R;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
            cin >> a[i][j], backup[i][j] = a[i][j];
    }
}
void attack(int x, int y, char dir) {
    if (a[x][y] == 0) return;
    int dx = 0, dy = 0;
    if (dir == 'E') dy = 1;
    else if (dir == 'W') dy = -1;
    else if (dir == 'S') dx = 1;
    else if (dir == 'N') dx = -1;
    else assert(false);
    int cnt = a[x][y];
    while (x >= 1 && x <= n && y >= 1 && y <= m && cnt >= 1) {
        if (a[x][y] != 0) ans++;
        cnt = max(cnt - 1, a[x][y] - 1);
        a[x][y] = 0;
        x += dx, y += dy;
    }
}
void pro() {
    for (int i = 1; i <= R; i++) {
        // attacker
        int X, Y;
        char dir;
        cin >> X >> Y >> dir;
        attack(X, Y, dir);

        // defender
        cin >> X >> Y;
        a[X][Y] = backup[X][Y];
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (a[i][j] == 0 ? "F" : "S") << " ";
        }
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
}
 */