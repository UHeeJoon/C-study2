#include<bits/stdc++.h>
using namespace std;
//#define MAX 1<<21
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, m, M, T, R; cin >> N >> m >> M >> T >> R;
	if (M - m < T) {
		cout << -1;
		return 0;
	}
	int pulse = m, minute(0);
	while (N) {
		if (pulse + T <= M) {
			pulse += T;
			N--;
		}
		else {
			pulse -= R;
			if (pulse < m) pulse = m;
		}
		minute++;
	}
	cout << minute << '\n';
	return 0;
}