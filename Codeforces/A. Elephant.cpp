#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x; cin >> x;
	int cnt = 0;
	cnt += x / 5, x %= 5;
	cnt += x / 4, x %= 4;
	cnt += x / 3, x %= 3;
	cnt += x / 2, x %= 2;
	cnt += x;
	cout << cnt << '\n';
	return 0;
}