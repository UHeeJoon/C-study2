#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	cout << (sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2)) < (r1 + r2) ? "YES\n" : "NO\n");
	return 0;
}