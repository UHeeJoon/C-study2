#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long A = 1, B = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp = A;
		A = B;
		B = tmp + B;
	}
	cout << A << ' ' << B << '\n';
	return 0;
}