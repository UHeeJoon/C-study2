#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef unsigned long long ull;
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++)cin >> v[i];
		int cnt(1);
		int tmp = v[1];
		while (cnt <= n && tmp != n) {
			tmp = v[tmp];
			cnt++;
		}
		cout << (cnt > n ? 0 : cnt) << '\n';
	}
	return 0;			  
}