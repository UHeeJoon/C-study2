#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int tc;  cin >> tc;
	while (tc--)
	{
		string str; cin >> str;
		int answer = 0;
		for (const char s : str)
		{
			char c;
			cin >> c;
			if (c != s) { answer++; }

		}
		cout << "Hamming distance is " << answer << ".\n";
	}
	return 0;
}