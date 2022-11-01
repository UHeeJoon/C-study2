#include<bits/stdc++.h>
using namespace std;
void print(int n, bool first) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 5; j++) {
			if (j / n == (first ? 3 : 1)) cout << ' ';
			else cout << '@';

		}
		cout << '\n';
	}
}
void print2(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 5; j++) {
			if (j / n == 3 || j / n == 1) cout << ' ';
			else cout << '@';
		}
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	print(n, 1);
	print2(n);
	print2(n);
	print2(n);
	print(n, 0);
	return 0;
}