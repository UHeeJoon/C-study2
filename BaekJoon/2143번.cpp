#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int A[1010], B[1010];
vector<ll> tmp;
int t, n, m;
ll cnt;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] = A[i - 1] + A[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] = B[i - 1] + B[i];
		for (int j = 0; j < i; j++) {
			tmp.push_back(B[i] - B[j]);
		}
	}
	sort(tmp.begin(), tmp.end());
	int s = 0, e = 1;
	while (e <= n) {
		int sum = A[e] - A[s];
		int diff = t - sum;
		auto ub = upper_bound(tmp.begin(), tmp.end(), diff);
		auto lb = lower_bound(tmp.begin(), tmp.end(), diff);
		cnt += (ub - lb);
		e += 1;
		if (e > n) {
			s += 1;
			e = s + 1;
		}
	}
	cout << cnt << '\n';
	return 0;
}