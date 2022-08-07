#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, attack, t[140005], a[140005], h[140005];
void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
bool check(ll mid) {
	ll init_hp = mid;
	ll init_attack = attack;
	for (int i = 0; i < n; i++) {
		if (t[i] == 2) {
			mid = min(init_hp, mid + h[i]);
			init_attack += a[i];
		}
		else {
			ll div = h[i] / init_attack + (h[i] % init_attack ? 1 : 0);
			ll attack_Cnt = div - 1;
			mid -= attack_Cnt * a[i];
		}
		if (mid <= 0) return false;
	}
	return true;
}
int main() {
	fastIO();
	cin >> n >> attack;
	ll init_lo = 1;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> a[i] >> h[i];
	}
	ll lo = 1, hi = 1e18 + 4, ret;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid)) {
			hi = mid - 1;
			ret = mid;
		}
		else lo = mid + 1;
	}
	cout << ret << '\n';
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, attack;
	long long cur = 0, mx = 0;
	cin >> n >> attack;

	while (n--) {
		int t, a, h;
		cin >> t >> a >> h;
		if (t == 1) {
			long long damage = a * (ceil((double)h / attack) - 1);
			if (damage > cur)mx += damage - cur, cur = 0;
			else cur -= damage;
		}
		else {
			attack += a;
			cur += h;
			if (cur > mx)cur = mx;
		}
	}
	cout << mx + 1 << endl;
	return 0;
}
*/