#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int sum = 0, sum2 = 0;
		for (int i = 0; i < s.length(); i++) {
			sum += (s[i] - 'a') + 1;
		}
		if (s.length() % 2 == 0)
			cout << "Alice " << sum << '\n';
		else {
			int tmp = min((s[0] - 'a') + 1, (s[s.length() - 1] - 'a') + 1);
			sum -= tmp;
			if (sum > tmp)
				cout << "Alice " << sum - tmp << '\n';
			else
				cout << "Bob " << tmp - sum << '\n';
		}
	}
}