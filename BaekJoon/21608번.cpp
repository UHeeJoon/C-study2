#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
struct student
{
	student() : me(0), like1(0), like2(0), like3(0), like4(0) {}
	int me;
	int like1;
	int like2;
	int like3;
	int like4;
};
constexpr int dr[] = { 0,1,0,-1 };
constexpr int dc[] = { 1,0,-1,0 };
bool check_nearby(const student me, const int near)
{
	if (me.like1 == near ||
		me.like2 == near ||
		me.like3 == near ||
		me.like4 == near)
	{
		return true;
	}
	return false;
}
void select_one(const vector<vector<student>>& grid, int& select_seat_row, int& select_seat_col, const int grid_size)
{
	for (int r = 0; r < grid_size; r++)
	{
		for (int c = 0; c < grid_size; c++)
		{
			if (grid[r][c].me == 0)
			{
				select_seat_row = r;
				select_seat_col = c;
				return;
			}
		}
	}
}
void select_seat(vector<vector<student>>& grid, const student current_student, const int grid_size)
{
	int select_seat_row = -1;
	int select_seat_col = -1;
	int select_seat_count = 0;
	int select_seat_space = 0;
	for (int r = 0; r < grid_size; r++)
	{
		for (int c = 0; c < grid_size; c++)
		{
			if (grid[r][c].me)continue;
			int count = 0;
			int space = 0;
			for (int i = 0; i < 4; i++)
			{
				const int nr = r + dr[i];
				const int nc = c + dc[i];
				if (nr < 0 || nr >= grid_size || nc < 0 || nc >= grid_size)continue;
				if (check_nearby(current_student, grid[nr][nc].me)) count++;
				if (grid[nr][nc].me == 0) space++;
			}
			if (select_seat_count < count)
			{
				select_seat_count = count;
				select_seat_space = space;
				select_seat_row = r;
				select_seat_col = c;
			}
			else if (select_seat_count == count && select_seat_space < space)
			{
				select_seat_space = space;
				select_seat_row = r;
				select_seat_col = c;
			}
		}
	}
	if (select_seat_row == -1) select_one(grid, select_seat_row, select_seat_col, grid_size);
	grid[select_seat_row][select_seat_col] = current_student;
}
int print_student_satisfaction(const vector<vector<student>>& grid)
{
	const int row = static_cast<int>(grid.size());
	const int col = static_cast<int>(grid[0].size());
	int total_score = 0;
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			int satisfaction = 0;
			for (int i = 0; i < 4; i++)
			{
				const int nr = r + dr[i];
				const int nc = c + dc[i];
				if (nr < 0 || nr >= row || nc < 0 || nc >= col)continue;
				if (check_nearby(grid[r][c], grid[nr][nc].me)) satisfaction++;
			}
			total_score += static_cast<int>(pow(10, satisfaction)) / 10;
		}
	}
	return total_score;
}
int main()
{
	FAST_IO;
	int grid_size; cin >> grid_size;
	const int student_num = grid_size * grid_size;
	vector<vector<student>> grid(grid_size, vector<student>(grid_size));
	vector<student>students(student_num);
	for (student& student : students)
	{
		cin >> student.me >> student.like1 >> student.like2 >> student.like3 >> student.like4;
	}
	for (const student student : students)
	{
		select_seat(grid, student, grid_size);
	}
	cout << print_student_satisfaction(grid) << '\n';
	return 0;
}