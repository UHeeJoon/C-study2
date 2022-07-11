#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;    
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, n, w; cin >> a >> b >> n >> w;
	int s, g, cnt = 0;
	for (int i = 1; i < n; i++) {
		if (a * i + b * (n - i) == w) {
			cnt++;
			s = i; g = n - i;
		}
	}
	if (cnt == 1)cout << s << ' ' << g << '\n';
	else cout << -1 << '\n';
	return 0;
}

