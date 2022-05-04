#include<bits/stdc++.h>
using namespace std;
#define MAX 130
int _map[MAX][MAX];
int w, b;
void dfs(int y, int x, int size) {
	bool one = true, zero = true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (_map[i][j] == 1) zero = false;
			if (_map[i][j] == 0) one = false;
		}
	}
	if (zero) {
		w++;
		return;
	}
	if (one) {
		b++;
		return;
	}
	dfs(y, x, size / 2);
	dfs(y, x + size / 2, size / 2);
	dfs(y + size / 2, x, size / 2);
	dfs(y + size / 2, x + size / 2, size / 2);
}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> _map[i][j];
	dfs(0, 0, n);
	cout << w << '\n' << b << '\n';
	return 0;
}