#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str, result = "";
	int cnt = 0;
	cin >> str;
	str.push_back(' ');

	for (int i = 0; i < str.size() - 1; i++) {

		if (str[i] == 'X') cnt++;

		if (str[i] == '.') {
			result.push_back('.');
			if (cnt % 2 != 0) break;
			else cnt = 0;
		}

		if (cnt == 2 && str[i + 1] != 'X') {
			result += "BB";
			cnt = 0;
		}
		else if (cnt == 4) {
			result += "AAAA";
			cnt = 0;
		}
	}

	if (cnt % 2 == 1) cout << -1 << '\n';
	else cout << result << '\n';
	return 0;
}