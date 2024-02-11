#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main()
{
	FAST_IO;
	string str;
	while (getline(cin, str) && !cin.eof()) {
		string::size_type idx;
		while ((idx = str.find("BUG")) != string::npos) {
			str = str.substr(0, idx) + str.substr(idx + 3);
		}

		cout << str << '\n';
	}
	return 0;
}