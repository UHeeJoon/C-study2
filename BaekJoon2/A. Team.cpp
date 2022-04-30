#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, cnt(0); cin >> n;
	while (n--) {
		int sum(0);
		for (int i = 0; i < 3; i++) {
			char tmp; cin >> tmp;
			sum += tmp - '0';
		}
		if (sum >= 2)
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}