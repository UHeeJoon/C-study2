#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
#define MOD 1000
typedef long long ll;
typedef vector<vector<ll>> matrix;
ll n, m;
matrix operator *(matrix& a, matrix& b) {
	matrix temp(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				temp[i][j] += a[i][k] * b[k][j];
			}
			temp[i][j] %= MOD;
		}
	}
	return temp;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	matrix a(n, vector<ll>(n)), b(n, vector<ll>(n)), ans(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		ans[i][i] = 1;
	}
	while (m) {
		if (m & 1)ans = ans * a;
		a = a * a;
		m /= 2;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}