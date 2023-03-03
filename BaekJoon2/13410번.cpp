#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void max_num(string& max, string tmp)
{
	if (max.length() == tmp.length())
	{
		for (int i = 0; i < static_cast<int>(max.length()); i++)
		{
			if (tmp[i] == max[i])
			{
				continue;
			}
			else if (tmp[i] > max[i])
			{
				max = tmp;
			}
			return;
		}
	}
	else if (max.length() < tmp.length())
	{
		max = tmp;
	}
}
int main()
{
	FAST_IO;
	int n, k; cin >> n >> k;
	string max = "0";
	for (int i = 1; i <= k; i++)
	{
		string tmp = to_string(i * n);
		while (!(tmp.back() - '0'))tmp.pop_back();
		reverse(tmp.begin(), tmp.end());
		max_num(max, tmp);
	}
	cout << max << '\n';
	return 0;
}