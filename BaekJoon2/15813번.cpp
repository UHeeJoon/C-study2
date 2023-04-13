#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int name_len; cin >> name_len;
	int score = 0;
	while (name_len--)
	{
		char name; cin >> name;
		score += (name - 'A') + 1;
	}
	cout << score << '\n';
	return 0;
}