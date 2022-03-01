#include <iostream>
#include<string>
using namespace std;
string s;
void three(string s, int cnt) {
	if ((int)s.length() == 1) {
		cout << cnt << '\n' << (stoi(s) % 3 == 0 ? "YES\n" : "NO\n");
		return;
	}
	int sum = 0;
	for (int i = 0; i < (int)s.length(); i++)
		sum += s[i] - 48;
	three(to_string(sum), cnt + 1);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	three(s, 0);
}