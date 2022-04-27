#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1){
		int n; cin >> n;
		if (!n)break;
		int facto = 1, i = 1, sum = 0;
		while (n) {
			sum += n % 10 * facto;
			n /= 10;
			facto = facto * ++i;
		}
		cout << sum << '\n';
	}
	return 0;
}