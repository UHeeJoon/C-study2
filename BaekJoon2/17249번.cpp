#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	string str; cin >> str;
	const string::size_type idx = str.find("(^0^)");
	string tmp = str.substr(0, idx);
	const int left = static_cast<int>(count(tmp.begin(), tmp.end(), '@'));
	tmp = str.substr(idx);
	const int right = static_cast<int>(count(tmp.begin(), tmp.end(), '@'));
	cout << left << ' ' << right << '\n';
	return 0;
}