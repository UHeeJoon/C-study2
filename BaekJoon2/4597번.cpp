#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	string str;
	while (true) {
		getline(cin, str);
		if (str == "#") {
			break;
		}
		int count = 0;
		for (const char c : str) {
			if (c == '1') {
				count++;
			}
		}
		char last = str[str.length() - 1];
		str[str.length() - 1] = ((last == 'e' && (count & 1) == 1) || (last == 'o' && (count & 1) == 0)) ? '1' : '0';
		cout << str << '\n';
	}
	return 0;
}