#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
stack<string> tokenize_getline(const string& data, const char delimiter = ' ')
{
	stack<string> result;
	string token;
	stringstream ss(data);
	while (getline(ss, token, delimiter))
	{
		result.push(token);
	}
	return result;
}
int main()
{
	FAST_IO;
	int n; cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++)
	{
		string data;
		getline(cin, data);
		stack < string> stk = tokenize_getline(data);
		cout << "Case #" << i << ": ";
		while (!stk.empty())
		{
			cout << stk.top() << ' ';
			stk.pop();
		}
		cout << '\n';
	}
	return 0;
}