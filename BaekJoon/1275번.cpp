#include<bits/stdc++.h>
using namespace std;
#define MAX 100'000 + 10
typedef long long ll;
ll num[MAX];
int n, q;
ll sum(int idx) {
	ll _sum = 0L;
	while (idx) {
		_sum += num[idx];
		idx -= (idx & -idx);
	}
	return _sum;
}
void update(int idx, ll diff) {
	while (idx <= n + 1) {
		num[idx] += diff;
		idx += (idx & -idx);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		update(i, num);
	}
	while (q--) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		if (x > y)
			swap(x, y);
		cout << sum(y) - sum(x - 1) << '\n';
		ll node = sum(a) - sum(a - 1);
		update(a, b - node);
	}
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
static void init(vector<int>& v, int idx, int num, int n) {
	while (idx <= n + 1) {
		v[idx] += num;
		idx += (idx & -idx);
	}
}
static int sum(vector<int>& v, int idx) {
	int _sum = 0;
	while (idx) {
		_sum += v[idx];
		idx -= (idx & -idx);
	}
	return _sum;
}
int main()
{
	FAST_IO;
	int n, l; cin >> n >> l;
	vector<int> v(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		init(v, i, num, n);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int _sum = sum(v, i) - sum(v, (i - l) < 0 ?  0 : i - l);
		if (129 <= _sum && _sum <= 138 ) {
			count++;
		}
	}
	cout << count << '\n';
	return 0;
}
*/