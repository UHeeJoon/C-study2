#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool check_palindrome(const string& str)
{
	for (string::size_type i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - i - 1])
		{
			return false;
		}
	}
	return true;
}
int main()
{

	FAST_IO;
	string str;
	cin >> str;
	cout << boolalpha << check_palindrome(str) << '\n';
	return 0;
}