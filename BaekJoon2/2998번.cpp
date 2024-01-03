#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
string binary_to_oct(const string str) {
	int bin[] = { 4, 2, 1 };
	int answer = 0;
	for (int i = 0; i < 3; i++) {
		if (str[i] - '0') {
			answer += bin[i];
		}
	}
	return to_string(answer);
}
int main()
{
	FAST_IO;
	string str; cin >> str;
	int len = static_cast<int>(str.length());
	string answer = "";
	if (len % 3) {
		for (int i = 0; i < 3 - len % 3; i++) {
			str = "0" + str;
		}
		len += 3 - len % 3;
	}
	for (int i = 0; i < len; i += 3) {
		answer += binary_to_oct(str.substr(i, 3));
	}
	cout << answer << '\n';
	return 0;
}