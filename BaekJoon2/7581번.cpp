#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		int l, w, h, v; cin >> l >> w >> h >> v;
		if (!l && !w && !h && !v)break;
		if (!v) cout << l << ' ' << w << ' ' << h << ' ' << l * w * h << '\n';
		else if (!l) cout << v / w / h << ' ' << w << ' ' << h << ' ' << v << '\n';
		else if (!w)cout << l << ' ' << v / l / h << ' ' << h << ' ' << v << '\n';
		else if (!h)cout << l << ' ' << w << ' ' << v / l / w << ' ' << v << '\n';
	}
	return 0;
}