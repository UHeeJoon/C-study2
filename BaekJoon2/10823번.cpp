#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
vector<string> split(string str)
{
	vector<string> tmp;
	string::size_type idx = 0;
	while ((idx = str.find(',')) != string::npos)
	{
		tmp.push_back(str.substr(0, idx));
		str = str.substr(idx + 1);
	}
	tmp.push_back(str);
	return tmp;
}
int main()
{
	FAST_IO;
	string str, s;
	int answer = 0;
	while (cin >> s && !cin.eof())
	{
		str += s;
	}
	for (const string& ss : split(str))
	{
		if (ss == (const char*)"") { continue; }
		answer += stoi(ss);
	}
	cout << answer << '\n';
	return 0;
}