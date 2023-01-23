#include<bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

typedef pair<int, int> location;
typedef tuple<int, location, int> type_location_time;
typedef vector<vector<int>> square_vector;

#define ROW first
#define COLUMN second
#define TYPE(type_location_time) get<0>(type_location_time)
#define LOCATION(type_location_time) {get<1>(type_location_time).ROW, get<1>(type_location_time).COLUMN}
#define TIME(type_location_time) get<2>(type_location_time)

constexpr int row_to_move[] = { 1,0,-1,0 };
constexpr int column_to_move[] = { 0,1,0,-1 };

bool is_exist(const int virus)
{
	return virus > 0;
}

bool check_out_of_size(const int test_tube_size, const int virus_row, const int virus_column)
{
	if (virus_row < 0 || virus_row >= test_tube_size || virus_column < 0 || virus_column >= test_tube_size) return true;
	return false;
}

void infect_virus(square_vector& test_tube, const int test_tube_size, queue<type_location_time>& viruses, const int time_to_check)
{
	while (!viruses.empty())
	{
		const type_location_time virus{ viruses.front() };
		viruses.pop();

		const int virus_type = TYPE(virus);
		const int time_current = TIME(virus) + 1;

		// end condition
		if (time_current > time_to_check) return;

		for (int move = 0; move < 4; move++)
		{
			const location virus_location = LOCATION(virus);
			const int virus_row = virus_location.ROW + row_to_move[move];
			const int virus_column = virus_location.COLUMN + column_to_move[move];

			if (check_out_of_size(test_tube_size, virus_row, virus_column) || is_exist(test_tube[virus_row][virus_column]))continue;

			test_tube[virus_row][virus_column] = virus_type;
			viruses.push({ virus_type, {virus_row, virus_column}, time_current });
		}
	}
}

void input_variables(queue<type_location_time>& viruses, square_vector& test_tube, const int test_tube_size)
{
	vector<type_location_time> sort_by_virus_type;

	for (int row = 0; row < test_tube_size; row++)
	{
		for (int col = 0; col < test_tube_size; col++)
		{
			int virus_type;
			cin >> virus_type;
			test_tube[row][col] = virus_type;
			if (is_exist(virus_type))
			{
				sort_by_virus_type.push_back({ virus_type,{row, col},0 });
			}
		}
	}

	sort(sort_by_virus_type.begin(), sort_by_virus_type.end());
	for (type_location_time& sort_by_virus_type_element : sort_by_virus_type)
	{
		viruses.push(sort_by_virus_type_element);
	}
}

void solve()
{
	FAST_IO;

	int test_tube_size, max_virus_type;
	cin >> test_tube_size >> max_virus_type;

	queue<type_location_time> viruses;
	square_vector test_tube(test_tube_size, vector<int>(test_tube_size));

	input_variables(viruses, test_tube, test_tube_size);

	int time_to_check, row_to_check, column_to_check;
	cin >> time_to_check >> row_to_check >> column_to_check;

	infect_virus(test_tube, test_tube_size, viruses, time_to_check);

	cout << test_tube[row_to_check - 1][column_to_check - 1] << '\n';
}

int main() {

	solve();

	return 0;
}



/*
// 다른 사람이 짠 코드...

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int n, k, x, y, s;
struct Virus {
	int x;
	int y;
	int v;
};
vector <Virus> board;
int lab[201][201]; //비어있는지 확인하기 위해

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool cmp(Virus a, Virus b) {
	return a.v < b.v;
}

void spread() {
	int vLen = board.size();
	for (int i = 0; i < vLen; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = board[i].x + dx[j];
			int ny = board[i].y + dy[j];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && lab[nx][ny] == 0) {
				lab[nx][ny] = board[i].v;
				board.push_back({ nx, ny, board[i].v });
			}
		}
	}
	board.erase(board.begin(), board.begin() + vLen); //이미 다 확인한 것은 다시 확인하지 않아도 됨
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int virus;
			cin >> virus;
			if(virus>0) board.push_back({ i, j, virus });
			lab[i][j] = virus;
		}
	}
	cin >> s >> x >> y;
	sort(board.begin(), board.end(), cmp);
	for (int i = 0; i < s; i++) spread();


	cout << lab[x - 1][y - 1];
}



 
 */