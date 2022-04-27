#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		long long even = 0, odd = 0;
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			int tmp;  cin >> tmp;
			if (tmp & 1)
				odd += tmp;
			else
				even += tmp;
		}
		if (even == odd)
			cout << "TIE\n";
		else if (even < odd)
			cout << "ODD\n";
		else
			cout << "EVEN\n";
	}
	return 0;
}