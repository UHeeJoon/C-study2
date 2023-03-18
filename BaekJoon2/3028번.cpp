#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	bool cup[3] = { true, false, false };
	string str; cin >> str;
	for (const char c : str)
	{
		switch (c)
		{
		case 'A':swap(cup[0], cup[1]); break;
		case 'B':swap(cup[1], cup[2]); break;
		case 'C':swap(cup[0], cup[2]); break;
		default:;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (cup[i])
		{
			cout << i + 1 << '\n';
			break;
		}
	}
	return 0;
}