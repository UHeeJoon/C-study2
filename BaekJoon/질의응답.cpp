#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 4010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s, t; cin >> s >> t;
	if (s == t) {
		cout << 1 << '\n';
		return 0;
	}
	while (s != t) {
		if (t[t.length() - 1] == 'A') {
			t.pop_back();
		}
		else if(t[t.length() - 1] == 'B') {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		if (s == t) {
			cout << 1 << '\n';
			return 0;
		}
		if (t.length() <= s.length()) {
			break;
		}
	}
	cout << 0 << '\n';
	return 0;
}