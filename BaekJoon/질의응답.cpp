#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef unsigned long long ull;
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
	cout << sum;
	return 0;			  
}