#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	priority_queue<int> pq;
	int n; cin >> n;
	while (n--)
	{
		int a; cin >> a;
		if (a == 0)
		{
			if (pq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		while (a--)
		{
			int value;
			cin >> value;
			pq.push(value);
		}
	}
	return 0;
}