#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	string str; cin >> str;
	string reg; cin >> reg;
	cout << (regex_replace(str, regex("[0-9]"), "").find(reg) != string::npos) << '\n';
	return 0;
}