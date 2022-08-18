#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	stack<pair<int, int>> stk;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		while (!stk.empty()) {
			if (stk.top().first > tmp) {
				cout << stk.top().second << ' ';
				break;
			}
			stk.pop();
		}
		if (stk.empty()) cout << 0 << ' ';
		stk.push({ tmp, i });
	}
	return 0;
}