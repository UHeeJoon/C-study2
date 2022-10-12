#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
#define MAX 100'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int friends[MAX];
int friend_cnt[MAX];
int cnt;
int getParent(int x) {
	if (friends[x] == x) return x;
	else return getParent(friends[x]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) friends[a] = b;
	else friends[b] = a;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		int F; cin >> F;
		map<string, int> _map;
		int p = 1;
		for (int i = 0; i < F; i++) {
			string s, s1; cin >> s >> s1;
			if (_map.find(s) != _map.end()) {
				_map[s] = p++;
			}
			if (_map.find(s1) != _map.end()) {
				_map[s1] = p++;
			}
			unionParent(_map[s], _map[s1]);
			getParent(_map[s]);
			getParent(_map[s1]);
			cout << cnt << '\n';
		}
	}
	return 0;
}