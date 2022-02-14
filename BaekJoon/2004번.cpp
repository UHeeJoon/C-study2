#include<iostream>
using namespace std; 
typedef long long ll;
int n, m;
ll Combi(ll temp, ll num) {
	temp = (temp / num) * num;
	ll ret = num, cnt = 0;
	while (ret <= temp) {
		cnt += temp / ret;
		ret *= num;
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	ll f1 = Combi(n, 5LL) - Combi(m, 5LL) - Combi(n - m, 5LL);
	ll t1 = Combi(n, 2LL) - Combi(m, 2LL) - Combi(n - m, 2LL);
	t1 < f1 ? cout << t1 << "\n" : cout << f1 << "\n";
}