#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef unsigned long long ull;
typedef long long ll;
ll fibo[80];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fibo[0] = fibo[1] = 1L; fibo[2] = 2L; fibo[3] = 4L;
	for (int i = 4; i <= 67; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2] + fibo[i - 3] + fibo[i - 4];
	}
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		cout << fibo[n] << '\n';
	}
	return 0;
}
