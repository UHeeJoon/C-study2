#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	if (n == 1)
		cout << 1 << '\n';
	else if (n == 2)
		cout << min(4, (m + 1) / 2) << '\n';
	else {
		if (m <= 6)
			cout << min(4, m) << '\n';
		else
			cout << m - 2 << '\n';
	}
	return 0;
}