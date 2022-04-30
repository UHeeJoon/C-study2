#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	while (n--) {
		string s = "";
		int a, b, c; cin >> a >> b >> c;
		while (b) {
			int tmp = b % (c + 1) == 0 ? b / (c + 1) : b / (c + 1) + 1;
			while (tmp--) {
				s += 'R';
				b--;
			}
			if (c > 0) {
				s += 'B';
				c--;
			}
		}
		cout << s << '\n';
	}
	return 0;
}