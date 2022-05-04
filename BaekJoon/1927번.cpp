#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<>> pq;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n; cin >> n;
	while (n--) {
		int tmp; cin >> tmp;
		if (tmp == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(tmp);
	}
	return 0;
}