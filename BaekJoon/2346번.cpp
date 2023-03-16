#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	deque<pair<int, int>> deq;
	queue<int> out;
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num; cin >> num;
		deq.emplace_back(i, num);
	}
	while (deq.size() > 1)
	{
		int num = deq.front().second;
		out.push(deq.front().first);
		deq.pop_front();
		if (num > 0)
		{
			while (num-- > 1)
			{
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else
		{
			while (num++)
			{
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
	}
	out.push(deq.front().first);
	while (!out.empty())
	{
		cout << out.front() << ' ';
		out.pop();
	}
	cout << '\n';
	return 0;
}