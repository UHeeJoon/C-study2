#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	string str;
	int n;
	while (cin >> str >> n && !cin.eof())
	{
		string tmp = str;
		int idx = 0;
		bool flag = false;
		do
		{
			if (++idx == n)
			{
				flag = true;
				break;
			}
		} while (next_permutation(tmp.begin(), tmp.end()));
		cout << str << ' ' << n << " = " << (flag ? tmp : "No permutation") << '\n';
	}
	return 0;
}