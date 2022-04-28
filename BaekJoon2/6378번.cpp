#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		string n; cin >> n;
		if (n == "0")break;
		while (n.length() != 1) {
			int sum = 0;
			for (int i = 0; i < n.length(); i++) {
				sum += (n[i] - '0');
			}
			n = to_string(sum);
		}
		cout << n << '\n';
	}
}