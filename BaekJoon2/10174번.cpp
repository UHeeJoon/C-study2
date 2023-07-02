#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool is_Palindrome(const string& str)
{
	bool flag = true;
	int start = 0, end = static_cast<int>(str.size()) - 1;
	while (start < end)
	{
		if (str[start++] != str[end--])
		{
			flag = false;
			break;
		}
	}
	return flag;
}
int main()
{
	FAST_IO;
	int n; cin >> n;
	cin.ignore();
	while (n--)
	{
		string str;
		getline(cin, str);
		for_each(str.begin(), str.end(), [](char& c)->void {c = c < 'a' ? static_cast<char>(c + 32) : c; });
		cout << (is_Palindrome(str) ? "Yes\n" : "No\n");
	}
	return 0;
}