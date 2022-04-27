#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int n; cin >> n;
		if (!n)break;
		cout << n << " => " << n * n - n + 1 << '\n';
	}
	return 0;
}