#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n; cin >> n;
	map<string, int> m;
	while (n--)
	{
		string str; cin >> str;
		const string::size_type idx = str.find('.');
		const string extension = str.substr(idx + 1);
		m[extension]++;
	}
	for (pair<string, int> ite : m)
	{
		cout << ite.first << ' ' << ite.second << '\n';
	}
	return 0;
}