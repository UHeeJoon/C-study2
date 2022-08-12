#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; getline(cin, s);
	string s2; getline(cin, s2);
	int i = 0, cnt = 0, pos = 0;
	while ((pos = s.find(s2)) != string::npos) {
		s.erase(0, pos + s2.size());
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}