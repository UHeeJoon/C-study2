// 23562번 ㄷ 만들기...
// https://www.acmicpc.net/problem/23562
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef vector<vector<char>> graph_paper;
int main()
{

	FAST_IO;
	int graph_paper_row, graph_paper_col;
	cin >> graph_paper_row >> graph_paper_col;
	graph_paper graph_paper(graph_paper_row, vector<char>(graph_paper_col));
	int white_to_black, black_to_white;
	cin >> white_to_black >> black_to_white;
	for (vector<char>& row : graph_paper)
	{
		for (char& element : row)
		{
			cin >> element;
		}
	}

	return 0;
}