//#pragma warning(disable : 4996)
//https://www.acmicpc.net/problem/15658
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void backtracking(const vector<int>& idx, vector<bool>& visited, vector<int>& answer, const int init_num, const int current_num)
{
	if(init_num < current_num)
	{
		answer.push_back(current_num);
		return;
	}
	for(vector<int>::size_type i = 0 ; i < idx.size(); i++)
	{
		if(!visited[i])
		{
			visited[i] = true;
			backtracking(idx, visited, answer, init_num, current_num * 10 + idx[i]);
			visited[i] = false;
		}
	}
}
int main()
{
	FAST_IO;
	string str;
	cin >> str;
	vector<int> idx;
	vector<bool> visited(str.length());
	for_each(str.begin(), str.end(), [&idx](const char c)-> void { idx.push_back(c - '0'); });
	const int init_num = stoi(str);
	vector<int> answer;
	backtracking(idx, visited, answer, init_num, 0);
	sort(answer.begin(), answer.end());
	cout << (!answer.empty() ? answer[0] : 0) << '\n';
	return 0;
}
