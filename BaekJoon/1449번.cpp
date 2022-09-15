#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l; cin >> n >> l;
	priority_queue<int, vector<int>, greater<>> pq;
	while (n--) {
		int a; cin >> a;
		pq.push(a);
	}

	int cnt = 1, comp = pq.top() + l; pq.pop();
	while (!pq.empty()) {
		if (comp <= pq.top()) {
			cnt++;
			comp = pq.top() + l;
			pq.pop();
		}
		else {
			pq.pop();
		}
	}
	cout << cnt << '\n';
	return 0;
}