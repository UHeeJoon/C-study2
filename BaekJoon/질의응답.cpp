#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef unsigned long long ull;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		ll n; cin >> n;
		if (!n)break;
		ll sum = 0;
		if (n & 1) {
			sum = n + (n / 2) * n;
		}
		else {
			sum = (n / 2) * (n + 1);
		}
		cout << sum << '\n';
	}
	return 0;
}