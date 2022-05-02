#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int alpha[27];
bool visited[27];
void dfs(int n) {
	string s;
	if (n == 2) {
		for (int i = 0; i < 2; i++) {
			s += (alpha[i] + 'a');
		}
		v.push_back(s);
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (!visited[i]) {
			visited[i] = true;
			alpha[n] = i;
			dfs(n + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	dfs(0);
	while (t--) {
		string s; cin >> s;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == s) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}