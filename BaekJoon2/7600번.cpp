#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	while (true)
	{
		string str; getline(cin, str);
		if (str == "#") { break; }
		bool alphabet[27] = { false, };
		int count = 0;
		for (const char c : str)
		{
			if ('a' <= c && c <= 'z')
			{
				if (!alphabet[c - 'a'])
				{
					alphabet[c - 'a'] = true;
					count++;
				}
			}
			else if ('A' <= c && c <= 'Z')
			{
				if (!alphabet[c - 'A'])
				{
					alphabet[c - 'A'] = true;
					count++;
				}
			}
		}

		cout << count << '\n';
	}
	return 0;
}