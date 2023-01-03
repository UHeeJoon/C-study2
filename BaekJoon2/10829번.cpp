#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll num; cin >> num;
	string str = "";
	while (num) {
		str += to_string(num % 2);
		num /= 2;
	}
	reverse(str.begin(), str.end());
	cout << str << '\n';
	return 0;
}