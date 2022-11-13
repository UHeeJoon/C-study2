#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<>> pq;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		pq.push(num);
	}
	while (m--) {
		ll sum = pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		pq.push(sum);
		pq.push(sum);
	}
	ll sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum << '\n';
	return 0;
}