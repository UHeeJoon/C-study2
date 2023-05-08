#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	string ans = "Eyfa";
	vector<string> str(n);
	vector<string> str2(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c; cin >> c;
			str[i] += string(2, c);
		}
	}
	for (string& s : str2)
	{
		cin >> s;
	}
	for (int i = 0; i < n; i++)
	{
		if (str[i] != str2[i])
		{
			ans = "Not Eyfa";
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}