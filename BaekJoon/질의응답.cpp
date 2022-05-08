#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
bool prime[1010];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; i * j <= n; j++) {
			if (!prime[i * j]) {
				prime[i * j] = true;
				k--;
				if (k == 0) {
					cout << i * j << '\n';
					break;
				}
			}
		}
		if (k == 0)break;
	}
	return 0;
}
