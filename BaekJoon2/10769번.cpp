#include<bits/stdc++.h>
using namespace std;
int emote(string& s, string tmp) {
	int cnt = 0;
	long long n = 0;
	while ((n = s.find(tmp)) != string::npos) {
		s.erase(n, tmp.length());
		cnt++;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	getline(cin, s);
	int cnt = emote(s, ":-)");
	int cnt2 = emote(s, ":-(");
	if (!cnt && !cnt2) {
		cout << "none\n";
	}
	else if (cnt > cnt2) {
		cout << "happy\n";
	}
	else if (cnt == cnt2) {
		cout << "unsure\n";
	}
	else {
		cout << "sad\n";
	}
	return 0;
}
