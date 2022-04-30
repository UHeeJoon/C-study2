#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s, result = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A' || s[i] == 'a') continue;
		else if (s[i] == 'O' || s[i] == 'o') continue;
		else if (s[i] == 'Y' || s[i] == 'y') continue;
		else if (s[i] == 'E' || s[i] == 'e') continue;
		else if (s[i] == 'U' || s[i] == 'u') continue;
		else if (s[i] == 'I' || s[i] == 'i') continue;
		else {
			s[i] = s[i] < 97 ? s[i] + 32 : s[i];
			result = result + "." + char(s[i]);
		}
	}
	cout << result << '\n';
	return 0;
}