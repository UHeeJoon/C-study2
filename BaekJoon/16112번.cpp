#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, k; cin >> n >> k;
	vector<ll>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ll sum = 0;
	sort(arr.begin(), arr.end());
	for (ll i = 1; i < n; i++) {
		ll tmp = arr[i] * min(i, k);
		sum += tmp;
	}
	cout << sum << '\n';
	return 0;
}