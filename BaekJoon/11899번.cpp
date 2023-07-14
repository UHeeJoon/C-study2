#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	stack<char> stk;
	string str; cin >> str;
	for (const char c : str)
	{
		if (!stk.empty() && stk.top() == '(' && c == ')')
		{
			stk.pop();
		}
		else {
			stk.push(c);
		}
	}
	cout << stk.size() << '\n';
	return 0;
}
