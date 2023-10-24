#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int toBit(const string& str)
{
	int bit = 0;
	for_each(str.begin(), str.end(), [&bit](const char& c) -> void
		{
			bit |= 1 << ((c - 'A') + 1);
		}
	);
	return bit;
}
int main()
{
	FAST_IO;
	const int mobis = toBit("MOBIS");
	string str; cin >> str;
	const int new_word = toBit(str);
	const int isMake = (mobis & new_word) == mobis;
	cout << (isMake ? "YES\n" : "NO\n");
	return 0;
}