#include<bits/stdc++.h>
using namespace std;
int check(int n) {
	int cnt = 0;
	while (n) {
		n % 2 == 1 ? cnt++ : cnt;
		n /= 2;
	}
	return cnt & 1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, b; cin >> n >> b;
		cout << (check(n) == b ? "Valid\n" : "Corrupt\n");
	}
	return 0;
}