#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(6); cout << fixed;
	int p; cin >> p;
	while (p--) {
		int N;
		double D, A, B, F; cin >> N >> D >> A >> B >> F;
		cout << N << ' ' << F * (D / (A + B)) << '\n';
	}
	return 0;
}