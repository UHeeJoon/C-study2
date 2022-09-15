#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
int cnt = 0;
int recursion(string &s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(string &s) {
    return recursion(s, 0, s.length() - 1);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while (tc--) {
        string s; cin >> s;
        cout << isPalindrome(s) << ' ' << cnt  << '\n';
        cnt = 0;
    }
	return 0;
}

