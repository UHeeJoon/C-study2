#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	unordered_set<string> _set;
	int n; cin >> n;
	char c; cin >> c;
	while (n--) {
		string str; cin >> str;
		_set.insert(str);
	}
	int div_num = 1;
	if (c == 'F') { div_num = 2; }
	else if (c == 'O') { div_num = 3; }
	cout << _set.size() / div_num << '\n';
	return 0;
}