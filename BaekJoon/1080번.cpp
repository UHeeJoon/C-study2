#include<bits/stdc++.h>
using namespace std;
char A[55][55];
char B[55][55];
int n, m;
int cnt;
void init(char tmp[55][55]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp[i][j];
		}
	}
}
void change(int y, int x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			A[i][j] = A[i][j] == '0' ? '1' : '0';
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	init(A); init(B);
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (A[i][j] != B[i][j]) {
				change(i, j);
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}