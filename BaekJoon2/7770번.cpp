#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int sum = 0, i = 1, j = 0, tmp = 0, cnt = 0;
	while (sum < n){
		sum += i * i - 4 * tmp;
		i += 2;
		tmp += ++j;
		cnt++;
	}
	if (sum > n) cout << cnt - 1 << '\n';
	else cout << cnt << '\n';
	return 0;
}