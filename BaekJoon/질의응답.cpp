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
	int n; cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; i * j <= n && j <= n ; j++) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
