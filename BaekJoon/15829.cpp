#include <iostream>
#include <string>
using namespace std;
const int MOD = 1234567891;
const int MULTIPLY = 31;
int main(void) {
	int L; cin >> L; 
	string s; cin >> s; 
	long long sum = 0;
	long long R = 1; 
	for (int i = 0; i < s.length(); i++) {
		sum = (sum + (s[i] - 'a' + 1) * R) % MOD;
		R = (R * MULTIPLY) % MOD;
	} 
	cout << sum << "\n"; return 0;
}
/*
#include<bits/stdc++.h>
#define MOD 1234567891
#define ll long long
using namespace std;
ll go(ll b) {
    if (b == 0) return 1;
    if (b == 1) return 31 % MOD;
    ll _c = go(b / 2);
    _c = (_c * _c) % MOD;
    if (b % 2)_c = (_c * 31) % MOD;
    return _c;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long sum = 0;
    string s;
    int l; cin >> l >> s;
    for (int i = 0; i < s.size(); i++) {
        sum =(sum + go(i) * (s[i] -'a' + 1)) % MOD;
    }
    cout << sum << '\n';
    return 0;
}
*/