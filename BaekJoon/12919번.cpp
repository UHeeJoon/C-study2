#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void ab(const string &str, const string& s)
{
	if (s.length() < 1)return;
	string tmp = s;
	if (str == s)
	{
		cout << 1 << '\n';
		exit(0);
	}
	if (s[0] == 'B')
	{
		reverse(tmp.begin(), tmp.end());
		tmp.pop_back();
		ab(str, tmp);
	}
	if (s[s.length() - 1] == 'A')
	{
		tmp = s;
		tmp.pop_back();
		ab(str, tmp);
	}
}
int main() {
	FAST_IO;
	string str, str2; cin >> str >> str2;
	ab(str, str2);
	cout << 0 << '\n';
	return 0;
}