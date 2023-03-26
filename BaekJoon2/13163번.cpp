#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int tc; cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string name; getline(cin, name);
		bool flag = false;
		cout << "god";
		for (const char c : name)
		{
			if (c == ' ') { flag = true; }
			if (!flag || c == ' ') { continue; }
			cout << c;
		}
		cout << '\n';
	}
	return 0;
}