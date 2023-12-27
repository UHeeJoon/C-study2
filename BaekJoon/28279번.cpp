#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	deque<int> dq;
	int n; cin >> n;
	while (n--) {
		int order; cin >> order;
		int num;
		switch (order)
		{
		case 1:
			cin >> num;
			dq.push_front(num);
			break;
		case 2:
			cin >> num;
			dq.push_back(num);
			break;
		case 3: case 4: case 7: case 8:
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				int ans = order == 3 || order == 7 ? dq.front() : dq.back();
				cout << ans << '\n';
				if (order == 3) { dq.pop_front(); }
				else if (order == 4) { dq.pop_back(); }
			}
			break;
		case 5:
			cout << dq.size() << '\n';
			break;
		case 6:
			cout << dq.empty() << '\n';
			break;
		default:
			break;
		}
	}
	return 0;
}