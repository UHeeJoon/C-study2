#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0;
	bool flag = false;
	for (int i = 0; i < 10; i++) {
		int num; cin >> num;
		if (flag)continue;
		if (abs(100 - sum) >= abs(100 - (sum + num))) {
			sum += num;
		}
		else flag = true;
	}
	cout << sum << '\n';
	return 0;
}