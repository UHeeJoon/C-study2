#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define CASTING(a) static_cast<int>(a)
bool cmp(const pair<int, int> a, const pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
void r_operation(vector<vector<int>>& matrix)
{
	int size = 0;
	const int matrix_size = CASTING(matrix.size());
	vector<vector<int>> tmp_matrix(matrix_size);
	vector<pair<int, int>>tmp_cal;
	for (int i = 0; i < matrix_size; i++)
	{
		map<int, int> tmp;
		for (const auto& col : matrix[i])
		{
			if (!col)continue;
			tmp[col]++;
		}
		for (auto a : tmp)
		{
			tmp_cal.emplace_back(a);
		}
		sort(tmp_cal.begin(), tmp_cal.end(), cmp);
		for (auto a : tmp_cal)
		{
			if (tmp_matrix[i].size() < 100)
			{
				tmp_matrix[i].push_back(a.first);
			}
			if (tmp_matrix[i].size() < 100)
			{
				tmp_matrix[i].push_back(a.second);
			}
		}
		size = max(size, CASTING(tmp_matrix[i].size()));
		tmp_cal.clear();
	}
	for (int i = 0; i < matrix_size; i++)
	{
		tmp_matrix[i].resize(size);
	}
	matrix.swap(tmp_matrix);
}
void c_operation(vector<vector<int>>& matrix)
{
	int size = 0;
	const int matrix_col_size = CASTING(matrix[0].size());
	const int matrix_row_size = CASTING(matrix.size());
	vector<vector<int>> tmp_matrix(100, vector<int>(100));
	vector<pair<int, int>>tmp_cal;
	for (int i = 0; i < matrix_col_size; i++)
	{
		map<int, int> tmp;
		for (int j = 0; j < matrix_row_size; j++)
		{
			if (!matrix[j][i])continue;
			tmp[matrix[j][i]]++;
		}
		for (auto a : tmp)
		{
			tmp_cal.emplace_back(a);
		}
		sort(tmp_cal.begin(), tmp_cal.end(), cmp);
		int idx = 0;
		for (const auto a : tmp_cal)
		{
			if (idx < 100)
			{
				tmp_matrix[idx++][i] = a.first;
			}
			if (idx < 100)
			{
				tmp_matrix[idx++][i] = a.second;
			}
		}
		size = max(size, idx);
		tmp_cal.clear();
	}
	tmp_matrix.resize(size);
	for (int i = 0; i < size; i++)
	{
		tmp_matrix[i].resize(matrix_col_size);
	}
	matrix.swap(tmp_matrix);

}
void operation(vector<vector<int>>& matrix, const int r, const int c, const int k, const int count)
{
	if (count > 100)
	{
		cout << -1 << '\n';
		return;
	}
	if (CASTING(matrix.size()) >= r && CASTING(matrix[0].size()) >= c && matrix[r - 1][c - 1] == k)
	{
		cout << count << '\n';
		return;
	}
	CASTING(matrix.size()) >= CASTING(matrix[0].size()) ? r_operation(matrix) : c_operation(matrix);
	operation(matrix, r, c, k, count + 1);
}
int main()
{
	FAST_IO;
	int r, c, k; cin >> r >> c >> k;
	vector<vector<int>> matrix(3, vector<int>(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> matrix[i][j];
		}
	}
	operation(matrix, r, c, k, 0);
	return 0;
}