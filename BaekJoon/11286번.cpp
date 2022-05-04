#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	int n; cin >> n;
	while (n--) {
		int tmp; cin >> tmp;
		if (tmp) {
			pq.push({ abs(tmp), tmp });
		}
		else {
			if (!pq.empty()) {
				cout << pq.top().second << '\n';
				pq.pop();
			}
			else
				cout << 0 << '\n';
		}
	}
	return 0;
}
