#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int a, b; cin >> a >> b;
		if (!a && !b)break;
		int tmp = 3 * min(a, b);
		int sum = a + b;
		cout << tmp - sum << '\n';
	}
	return 0;
}