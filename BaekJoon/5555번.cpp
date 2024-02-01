#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	string str; cin >> str;
	int n; cin >> n;
	int count = 0;
	while (n--)
	{
		string tmp; cin >> tmp;
		tmp += tmp;
		count += tmp.find(str) != string::npos ? 1 : 0;
	}
	cout << count << '\n';
	return 0;
}