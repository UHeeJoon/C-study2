#include<bits/stdc++.h>
using namespace std;
int n, m;
bool visited[11];
string str[11];
map<string, int> _map;
void make_num(int idx, string s) {
	if (idx == m) {
		_map[s] = 1;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			make_num(idx + 1, s + str[i]);
			visited[i] = false;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	make_num(0, "");
	cout << _map.size() << '\n';
	return 0;
}