#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 2147483647

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<long long, vector<long long>, greater<>> pq;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int card; cin >> card;
		pq.push(card);
	}
	long long sum = 0;
	long long left = 0, right = 0;
	while (!pq.empty()) {
		left = pq.top(); pq.pop();
		if (pq.empty()) {
			sum += left;
			break;
		}
		right = pq.top(); pq.pop();
		sum += (left + right);
		if (!pq.empty())
			pq.push((left + right));
		//cout << left << ' ' << right << ' ' << sum << '\n';
	}
	if (n > 1)
		cout << sum << '\n';
	else cout << 0 << '\n';
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> Q;

int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

cin >> N;
// ���ĵ� ������ �Ѱ��� ������ ���� �ʿ� ����.
if (N == 1) {
	cout << 0 << '\n';
	return 0;
}

for (int i = 0; i < N; ++i) {
	int a;
	cin >> a;
	Q.push(a);
}
int ans = 0;
// �ִ��� ���� �ֵ��� ���� ���´�.
while (Q.size() > 1) {
	int a = Q.top();
	Q.pop();
	int b = Q.top();
	Q.pop();
	ans += a + b;
	Q.push(a + b);
}
cout << ans << '\n';

return 0;
}
*/