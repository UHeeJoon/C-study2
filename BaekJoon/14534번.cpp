#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void backtracking(const string& str, vector<bool>& visited, const string& answer)
{
	if (answer.length() == str.length())
	{
		cout << answer << '\n';
		return;
	}
	for (string::size_type i = 0; i < str.length(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			backtracking(str, visited, answer + str[i]);
			visited[i] = false;
		}
	}
}
int main()
{
	FAST_IO;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		vector<bool> visited(str.length());
		cout << "Case # " << (i + 1) << ":\n";
		backtracking(str, visited, "");
	}
	return 0;
}