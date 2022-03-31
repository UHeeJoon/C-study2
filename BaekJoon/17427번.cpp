#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long sum(0), num; cin >> num;
	for (int i = 1; i <= num; i++)
		sum += (num / i) * i;
	cout << sum << '\n';
	return 0;
}