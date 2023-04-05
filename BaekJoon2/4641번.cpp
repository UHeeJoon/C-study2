#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	vector<int>num;
	vector<bool>visited(202);
	while (true)
	{
		int n; cin >> n;
		if (n == -1) { break; }
		if (n == 0)
		{
			int count = 0;
			for (const int ele : num)
			{
				if (visited[ele * 2])
				{
					count++;
				}
			}
			cout << count << '\n';
			vector<int>().swap(num);
			vector<bool>(202).swap(visited);
			continue;
		}
		num.push_back(n);
		visited[n] = true;
	}
	return 0;
}