#include<bits/stdc++.h>
using namespace std;
struct TRIE {
	TRIE* Node[26];
	TRIE() {
		for (int i = 0; i < 26; i++) {
			Node[i] = NULL;
		}
	}
	void insert(char* str) {
		if (*str == '\0') return;
		int Cur = *str - 'a';
		if (Node[Cur] == NULL) Node[Cur] = new TRIE();
		Node[Cur]->insert(str + 1);
	}
	bool find(char* str) {
		if (*str == '\0') return true;
		int Cur = *str - 'a';
		if (Node[Cur] == NULL) return false;
		return Node[Cur]->find(str + 1);
	}
};
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	TRIE* Root = new TRIE();
	char str[510] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> str;
		Root->insert(str);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (Root->find(str)) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}