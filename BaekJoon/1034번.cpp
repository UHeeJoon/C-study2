#include<bits/stdc++.h>
using namespace std;
//#define MAX 20010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int n, m, k, answer = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	unordered_map<string, pair<int, int>> ma;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		ma[str].first++;
		if (ma[str].second == 0) {
			int cnt = 0;
			for (int j = 0; j < str.length(); j++) {
				if (str[j] == '0')
					cnt++;
			}
			ma[str].second = cnt;
		}
	}
	cin >> k;
	for (auto a : ma) {
		int cnt = a.second.second;
		if (cnt <= k && cnt % 2 == k % 2) {
			answer = max(answer, a.second.first);
		}
	}

	cout << answer;
	return 0;
}