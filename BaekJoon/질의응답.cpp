#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
#define MAX 110
#define INF 2147483647

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1;;i++) {
		int l, p, v; cin >> l >> p >> v;
		if (!l && !p && !v) break;
		cout << "Case " << i << ": " << l * (v / p) + ((v % p) > l ? l : v % p) << '\n';;
	}
	return 0;
}

