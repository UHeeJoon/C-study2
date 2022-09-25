#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s, s2;
	while (cin >> s >> s2 && !cin.eof()) {
		int idx = 0;
		bool subS = false;
		for (int i = 0; i < s2.length(); i++) {
			if (s[idx] == s2[i]) {
				idx++;
			}
			if (idx == s.length()) {
				subS = true;
			}
		}
		if (subS)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}