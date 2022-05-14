#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	bool flag = false;
	for (int i = 0; i < 31; i++) {
		if (n == 1 << i) {
			flag = true;
			break;
		}
	}
	cout << (flag ? 1 : 0) << '\n';
	return 0;
}