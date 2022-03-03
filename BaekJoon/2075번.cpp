#include<iostream>
#include<queue>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			pq.push(tmp);
			if (pq.size() > n) pq.pop();
		}
	}
	cout << pq.top() << '\n';
	return 0;
}