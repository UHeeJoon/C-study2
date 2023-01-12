#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int A[55] = { 0, }, B[55] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
	int i = 0, j = 0;
	for (i; i < n; i++) {
		for (j; j < m; j++) {
			if (A[i] - B[j] >= 0)A[i] -= B[j];
			else break;
		}
	}
	int cnt = 0;
	for (i = 0; i < n; i++) {
		cnt += A[i];
	}
	cout << cnt << '\n';
	return 0;
}