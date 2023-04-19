#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
string comp(const string& original, const string& cmp_string)
{
	for (string::size_type i = 0; i < original.length(); i++)
	{
		if (i >= cmp_string.length())
		{
			return cmp_string;
		}
		const int o = original[i] < 97 ? original[i] + 32 : original[i];
		const int c = cmp_string[i] < 97 ? cmp_string[i] + 32 : cmp_string[i];
		if (o > c)
		{
			return cmp_string;
		}
		if (o < c)
		{
			return original;
		}
	}
	return original;
}
int main()
{
	FAST_IO;
	while (true)
	{
		int n; cin >> n;
		if (n == 0)
		{
			break;
		}
		string result; cin >> result;
		for (int i = 0; i < n - 1; i++)
		{
			string str; cin >> str;
			result = comp(result, str);
		}
		cout << result << '\n';
	}
	return 0;
}