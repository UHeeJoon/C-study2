#include<bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define VIRUS_ROW(virus) get<1>(virus).first
#define VIRUS_COLUMN(virus) get<1>(virus).second
#define TIME(virus) get<2>(virus)
#define TYPE(virus) get<0>(virus)


typedef tuple<int, pair<int, int>, int> virus_type_location_time;
typedef vector<vector<int>> square_vector;

constexpr int row_to_move[] = { 1,0,-1,0 };
constexpr int column_to_move[] = { 0,1,0,-1 };

bool is_exist(const int virus)
{
	return virus > 0;
}

bool check_out_of_size(const int size_test_tube, const int row_of_virus, const int column_of_virus)
{
	if (row_of_virus < 0 || row_of_virus >= size_test_tube || column_of_virus < 0 || column_of_virus >= size_test_tube) return true;
	return false;
}

void infect_virus(square_vector& test_tube, const int size_test_tube, queue<virus_type_location_time>& viruses, const int time_to_check)
{
	while (!viruses.empty())
	{
		const virus_type_location_time virus{ viruses.front() };
		viruses.pop();

		const int type_of_virus = TYPE(virus);
		const int time_current = TIME(virus) + 1;

		// end condition
		if (time_current > time_to_check) return;

		for (int move = 0; move < 4; move++)
		{
			const int row_of_virus = VIRUS_ROW(virus) + row_to_move[move];
			const int column_of_virus = VIRUS_COLUMN(virus) + column_to_move[move];

			if (check_out_of_size(size_test_tube, row_of_virus, column_of_virus) || is_exist(test_tube[row_of_virus][column_of_virus]))continue;

			test_tube[row_of_virus][column_of_virus] = type_of_virus;
			viruses.push({ type_of_virus, {row_of_virus, column_of_virus}, time_current });
		}
	}
}

int main() {
	FAST_IO;

	int size_test_tube, max_virus_type;
	cin >> size_test_tube >> max_virus_type;

	queue<virus_type_location_time> viruses;
	vector<virus_type_location_time> tmp_sort_by_virus_type;
	square_vector test_tube(size_test_tube, vector<int>(size_test_tube));

	for (int row = 0; row < size_test_tube; row++)
	{
		for (int col = 0; col < size_test_tube; col++)
		{
			int virus_type;
			cin >> virus_type;
			test_tube[row][col] = virus_type;
			if (is_exist(virus_type))
			{
				tmp_sort_by_virus_type.push_back({ virus_type,{row, col},0 });
			}
		}
	}

	sort(tmp_sort_by_virus_type.begin(), tmp_sort_by_virus_type.end());
	for (virus_type_location_time& sort_by_virus_type_element : tmp_sort_by_virus_type)
	{
		viruses.push(sort_by_virus_type_element);
	}

	// free memory
	vector<virus_type_location_time>().swap(tmp_sort_by_virus_type);

	int time_to_check, row_to_check, column_to_check;
	cin >> time_to_check >> row_to_check >> column_to_check;

	infect_virus(test_tube, size_test_tube, viruses, time_to_check);

	cout << test_tube[row_to_check - 1][column_to_check - 1] << '\n';

	return 0;
}
