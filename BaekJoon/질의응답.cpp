#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<string, int> mp;
    map<string, int> a;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if (mp[s]) {
            cout << s;
            if (++a[s] > 1) cout << a[s];
            cout << '\n';
            continue;
        }
        string t;
        string ans;
        for (int j = 0; j < s.size(); j++) {
            t += s[j];
            if (mp[t] == 0 and ans.size() == 0) ans = t;
            mp[t]++;
        }
        cout << ans << '\n';
        ++a[s];
    }
	return 0;
}