#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n; cin >> n;
	stack<int> stk;
	int idx = 1;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num != idx) {
			stk.push(num);
			continue;
		}
		while ((!stk.empty() && stk.top() == idx) || num == idx) {
			if (!stk.empty() && stk.top() == idx) {
				stk.pop();
			}
			idx++;
		}
	}
	cout << (!stk.empty() ? "Sad\n" : "Nice\n");
	return 0;
}