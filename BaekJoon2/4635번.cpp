#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int n; cin >> n;
		if (n == -1)break;
		int dis = 0, time = 0;
		while(n--) {
			int s, t; cin >> s >> t;
			dis += s * (t - time);
			time = t;
		}
		cout << dis << " miles\n";
	}
	return 0;
}