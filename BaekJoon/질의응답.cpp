#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
string s, s2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s >> s2;
	long long sum = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			sum += (s[i] - '0') * (s2[j] - '0');
		}
	}
	cout << sum << '\n';
	return 0;
}