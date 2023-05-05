#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int tc; cin >> tc;
	while (tc--)
	{
		string str; cin >> str;
		string::size_type idx;
		if ((idx = str.find('+')) == string::npos)
		{
			cout << "skipped\n";
			continue;
		}
		const int f = stoi(str.substr(0, idx));
		const int b = stoi(str.substr(idx + 1));
		cout << f + b << '\n';
	}
	return 0;
}