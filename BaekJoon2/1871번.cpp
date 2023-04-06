#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int tc; cin >> tc;
	while (tc--)
	{
		string str;
		cin >> str;
		string f = str.substr(0, 3);
		int front = 0;
		for (int i = 0; i < 3; i++)
		{
			front += (f[i] - 'A') * static_cast<int>(pow(26, 2 - i));
		}
		const int back = stoi(str.substr(4));
		const int ans = abs(front - back);
		if (ans <= 100)
		{
			cout << "nice\n";
		}
		else
		{
			cout << "not nice\n";
		}
	}
	return 0;
}