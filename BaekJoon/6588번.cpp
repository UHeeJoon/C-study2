#include<bits/stdc++.h>
using namespace std;
bool num[1000010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	num[1] = true;
	for (int i = 2; i <= sqrt(1000000); i++) {
		for (int j = i + i; j <= 1000000; j += i) {
			if (num[j]) continue;
			num[j] = true;
		}
	}
	while (1) {
		bool isSosu = false;
		int n; cin >> n;
		if (!n) break;
		for (int i = 1; i < n / 2; i++) {
			int start = 2 * i + 1, end = n - start;
			if (!num[start] && !num[end]) {
				cout << n << " = " << start << " + " << end << '\n';
				isSosu = true;
				break;
			}
		}
		if (!isSosu)
			cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}