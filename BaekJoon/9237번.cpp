#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int arr[100010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n, greater<>());
	int max_day = arr[0] - 1;
	int day = 2, ans = arr[0], idx = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > max_day) {
			max_day = ans = arr[i];
			day += idx;
			idx = 0;
		}
		idx++;
		max_day--;
	}
	cout << ans + day << '\n';
	return 0;
}