#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int idx = 0, cnt = 987654321;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1')
				idx = i;
			else if (s[i] == '0')
				cnt = min(cnt, i - idx);
		}
		if (cnt == 0)cnt = s.length();
		cout << cnt + 1 << '\n';
	}
	return 0;
}
