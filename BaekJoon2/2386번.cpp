#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	while (true)
	{
		char c; cin >> c;
		if (c == '#')break;
		string eng; getline(cin, eng);
		int count = 0;
		for (const char element : eng)
		{
			if (element == c || static_cast<char>(element + 32) == c)
			{
				count++;
			}
		}
		cout << c << ' ' << count << '\n';
	}
	return 0;
}