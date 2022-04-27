#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A')
			cnt++;
	}
	n = n - cnt;
	if (n == cnt)
		cout << "Friendship\n";
	else if (n > cnt)
		cout << "Danik\n";
	else
		cout << "Anton\n";
	return 0;
}