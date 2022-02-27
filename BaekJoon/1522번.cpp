#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	int a = 0, ans = (int)s.size();
	for (auto c : s) if (c == 'a')a++;
	for (int i = 0; i < (int)s.size(); i++) {
		int cnt = a, temp = 0;
		for (int j = i; j < i + (int)s.size(); j++) {
			if (cnt == 0) break;
			if (s[j % s.size()] == 'b')temp++, cnt--;
			else cnt--;
		}
		ans = min(ans, temp);
	}
	cout << ans << "\n";
	return 0;
}