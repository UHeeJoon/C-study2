#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int i = 0, j = 0;
	long long sum = 0;
	int cnt = 0;
	while (i <= j && j <= n) {
		if (sum < n)
			sum += ++j;
		else if (sum > n)
			sum -= ++i;
		else {
			i++, j++, cnt++, sum += j - i;
		}
	}
	cout << cnt << '\n';
	return 0;
}