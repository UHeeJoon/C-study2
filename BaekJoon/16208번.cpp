#include<bits/stdc++.h>
using namespace std;
#define MAX 500'010
//#define INF 2'100'000'000
//#define MOD 1000
typedef long long ll;
int arr[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int sum = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++) {
		ans += (sum - arr[i]) * arr[i];
		sum -= arr[i];
	}
	cout << ans << '\n';
	return 0;
}