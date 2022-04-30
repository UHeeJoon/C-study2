#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, sum = 0, result = 0; cin >> n;
	while (n--) {
		int tmp, tmp2; cin >> tmp >> tmp2;
		sum += tmp2 - tmp;
		result = max(sum, result);
	}
	cout << result << '\n';
	return 0;
}