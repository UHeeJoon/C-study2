#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int cnt = 1;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == 'S')cnt++;
		if (flag) {
			cnt++;
			flag = false;
			continue;
		}
		if (c == 'L')flag = true;
	}
	cout << (cnt > n ? n : cnt) << '\n';
	return 0;
}