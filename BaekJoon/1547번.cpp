#include<iostream>
using namespace std
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, cup = 1; cin >> n;
	while (n--) {
		int n, m; cin >> n >> m;
		if (n == cup)
			cup = m;
		else if (m == cup)
			cup = n;
	}
	cout << cup << '\n';
	return 0;
}