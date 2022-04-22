#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int a, b, c; cin >> a >> b >> c;
		if (!a && !b && !c)break;
		if ((c - a + b) % b || (b && a > c))
			cout << "X\n";
		else
			cout << (c - a + b) / b << '\n';
	}
	return 0;
}