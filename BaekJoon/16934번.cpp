#include<bits/stdc++.h>
using namespace std;
map<string, int> _map;
struct TRIE {
	TRIE* Node[26];
	TRIE() {
		for (int i = 0; i < 26; i++)
			Node[i] = NULL;
	}
	~TRIE() {
		for (int i = 0; i < 26; i++) if (Node[i])delete Node[i];
	}
	void insert(string str, int idx = 0, bool ismake = false) {
		if (str[idx] == '\0') {
			if (!ismake) {
				cout << str << '\n';
				ismake = true;
			}
			return;
		}
		int Cur = str[idx] - 'a';
		if (Node[Cur] == NULL) {
			Node[Cur] = new TRIE();
			if (!ismake) {
				string ans(str.begin(), str.begin() + idx + 1);
				cout << ans << '\n';;
				ismake = true;
			}
		}
		Node[Cur]->insert(str, idx + 1, ismake);
	}
};
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	TRIE* Root = new TRIE();
	for (int i = 0; i < n; i++) {
		string nik_name; cin >> nik_name;
		if (!_map[nik_name])
			Root->insert(nik_name);
		else
			cout << nik_name << _map[nik_name] + 1 << '\n';
		_map[nik_name]++;
	}
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	map<string, int> mp;
	map<string, int> a;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (mp[s]) {
			cout << s;
			if (++a[s] > 1) cout << a[s];
			cout << '\n';
			continue;
		}
		string t;
		string ans;
		for (int j = 0; j < s.size(); j++) {
			t += s[j];
			if (mp[t] == 0 and ans.size() == 0) ans = t;
			mp[t]++;
		}
		cout << ans << '\n';
		++a[s];
	}
	return 0;
}
*/