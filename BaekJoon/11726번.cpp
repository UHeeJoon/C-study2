#include<bits/stdc++.h>
using namespace std;
#define MOD 10007
int n, square[2010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	square[1] = 1 , square[2] = 2;
	for (int i = 3; i <= n; i++) {
		square[i] = (square[i - 1] + square[i - 2]) % MOD;
	}
	cout << square[n];
}