//#pragma warning(disable : 4996)
// 13702번 이상한 술집...
// https://www.acmicpc.net/problem/5212
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool check_pal(const string& str)
{
	for (string::size_type i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	FAST_IO;
	string str; cin >> str;
	int idx = 0;
	string tmp = str;
	while (!check_pal(tmp))
	{
		tmp = str;
		for (int i = idx++; i >= 0; i--)
		{
			tmp += str[i];
		}
	}
	cout << str.length() + idx << '\n';
	return 0;
}
/**
 *
asdasd
asdasdasd
 */