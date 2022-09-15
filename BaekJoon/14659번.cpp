#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int _max = 0, cnt = 0, h = 0;
	while (n--) {
		int a;
		cin >> a;
		if (h < a) {
			_max = max(cnt, _max);
			h = a;
			cnt = 0;
		}
		else {
			cnt++;
		}
	}
	cout << max(_max, cnt) << '\n';
	return 0;
}