#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int solve_max(const vector<int>& tmp)
{
	int _max = 0;
	for (int i = 1; i < static_cast<int>(tmp.size()); i++)
	{
		_max = max(_max, tmp[i] - tmp[i - 1]);
	}
	return _max;
}
int main()
{
	FAST_IO;
	int c, r; cin >> c >> r;
	vector<int> row, col;
	int tc; cin >> tc;
	row.push_back(0);
	col.push_back(0);
	while (tc--)
	{
		int what, num; cin >> what >> num;
		if (what)
		{
			col.push_back(num);
		}
		else
		{
			row.push_back(num);
		}
	}
	sort(col.begin(), col.end());
	sort(row.begin(), row.end());
	col.push_back(c);
	row.push_back(r);
	const int r_max = solve_max(row), c_max = solve_max(col);
	cout << r_max * c_max << '\n';
	return 0;
}