#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main()
{
	FAST_IO;
	string str;
	cin >> str;
	int num = 0, ptr = 0;
	while (num++ < 30000) {
		string num2str = to_string(num);
		for (int i = 0; i < num2str.length(); i++) {
			if (str[ptr] == num2str[i]) {
				ptr++;
			}
			if (ptr == str.length()) {
				cout << num;
				return 0;
			}
		}
	}
	return 0;
}