#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	const vector<string> promise = {
		"Never gonna give you up",
		"Never gonna let you down",
		"Never gonna run around and desert you",
		"Never gonna make you cry",
		"Never gonna say goodbye",
		"Never gonna tell a lie and hurt you",
		"Never gonna stop"
	};
	int tc; cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string str;
		getline(cin, str);
		const bool isHack = static_cast<int>(find(promise.begin(), promise.end(), str) - promise.begin()) == static_cast<int>(promise.size());
		if (isHack)
		{
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}