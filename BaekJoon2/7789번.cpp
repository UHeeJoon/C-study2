#include<bits/stdc++.h>
using namespace std;
bool is_prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	cout << ((is_prime(n) && is_prime(stoi(to_string(m) + to_string(n))) ? "Yes\n" : "No\n"));
	return 0;
 }