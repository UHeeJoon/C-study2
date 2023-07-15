#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void backtracking(const vector<int>& v, const int n, const long long value, long long& answer, const int idx, const int endPoint)
{
	if (idx == endPoint + 1)
	{
		return;
	}
	for (const int el : v)
	{
		answer = value > answer && value <= n ? value : answer;
		backtracking(v, n, value * 10 + el, answer, idx + 1, endPoint);
	}
}
int main()
{
	FAST_IO;
	string n; int k;
	cin >> n >> k;
	vector<int> v(k);
	for (int& element : v)
	{
		cin >> element;
	}
	long long answer = -1;
	backtracking(v, stoi(n), 0, answer, 0, static_cast<int>(n.length()));
	cout << answer << '\n';
	return 0;
}