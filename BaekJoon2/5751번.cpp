#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1){
		int n, cnt = 0;
		cin >> n;
		if (!n)break;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (a == 0)cnt++;
		}
		cout << "Mary won " << cnt << " times and John won " << n - cnt << " times\n";

	}
	return 0;
}