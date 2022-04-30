#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int i = 0;
	while (n <= m) {
		i++;
		n *= 3; m *= 2;
	}
	cout << i << '\n';
	return 0;
}