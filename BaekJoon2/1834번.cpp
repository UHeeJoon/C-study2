#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n; cin >> n;
	long long sum = 0;
	for (long long i = 1; i < n; i++) {
		sum += n * i + i;
	}
	cout << sum << '\n';
	return 0;
}