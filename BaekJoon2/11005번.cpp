#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, b; cin >> n >> b;
	string s = "";
	while (n) {
		int tmp = n % b;
		if (tmp > 9) s.push_back('A' + tmp - 10);
		else s.push_back('0' + tmp);
		n /= b;
	}
	reverse(s.begin(), s.end());
	cout << s << '\n';
	return 0;
}