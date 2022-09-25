#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int> pq;
	int n; cin >> n;
	int dasom; cin >> dasom;
	n--;
	while (n--) {
		int num; cin >> num;
		pq.push(num);
	}
	int cnt = 0;
	while (!pq.empty() && pq.top() >= dasom) {
		int tmp = pq.top(); tmp--;
		pq.pop();
		pq.push(tmp);
		dasom++;
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}