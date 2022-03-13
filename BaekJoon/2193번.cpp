#include<bits/stdc++.h>
using namespace std;
long long N[91];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	N[1] = 1;
	int n;
	cin >> n;
	if (n > 1) {
		for (int i = 2; i <= n; i++)
			N[i] = N[i - 1] + N[i - 2];
	}
	cout << N[n] << '\n';
	return 0;
}