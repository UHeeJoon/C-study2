#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	while (true)
	{
		bool alpha[27] = { false, };
		string str;
		getline(cin, str);
		if (str == "*")
		{
			break;
		}
		int sum = 0;
		for_each(str.begin(), str.end(), [&alpha](const char c)->void {alpha[c - 'a'] = true; });
		for_each(alpha + 0, alpha + 26, [&sum](const bool& a)-> void {sum += a; });
		cout << (sum == 26 ? "Y\n" : "N\n");
	}
	return 0;
}