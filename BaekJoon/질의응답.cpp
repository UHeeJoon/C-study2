//#pragma warning(disable : 4996)
//https://www.acmicpc.net/problem/1996
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n; cin >> n;
	unordered_map<string, int> chat;
	int ans = 0;
	while(n--)
	{
		string str; cin >> str;
		if(str == "ENTER")
		{
			ans += chat.size() - 1;
			unordered_map<string, int>().swap(chat);
		}
		chat[str]++;
	}
	cout << ans + chat.size() << '\n';
	return 0;
}