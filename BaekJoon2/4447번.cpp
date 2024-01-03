#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int tc; cin >> tc;
	cin.ignore();
	while (tc--) {
		string str;
		getline(cin, str);
		int g = 0, b = 0;
		for (const char& c : str) {
			if (c == 'g' || c == 'G') g++;
			else if (c == 'b' || c == 'B') b++;
		}
		if (g == b) {
			cout << str + " is NEUTRAL\n";
		}
		else if (g > b) {
			cout << str + " is GOOD\n";
		}
		else {
			cout << str + " is A BADDY\n";
		}
	}
	return 0;
}