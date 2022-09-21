#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int arr[10010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l; cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr[num]++;
	}
	int left = 1, right = l, ans = 0;
	while (1) {
		int cnt = 0;
		while (left <= right) {
			cnt += arr[left];
			arr[left] = 0;
			left++;
		}
		if (cnt == 0)break;
		left -= 1;
		right += cnt;
		ans += cnt;
	}
	cout << right << '\n';
	return 0;
}