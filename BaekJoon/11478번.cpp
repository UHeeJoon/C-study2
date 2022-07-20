#include<bits/stdc++.h>
using namespace std;
unordered_set<string> _set;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++)
		for (int j = 1; j <= s.length() - i; j++)
			_set.insert(s.substr(i, j));
	cout << _set.size() << '\n';
	return 0;
}
/*
// Æ®¶óÀÌ
#include<bits/stdc++.h>
using namespace std;
int nxt[1000005][26];
bool chk[1000005];
int root = 1;
int id = 1;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
	int cur = root;
	for (int j = i; j < s.size(); ++j) {
	  int c = s[j] - 'a';
	  if (nxt[cur][c] == 0)  nxt[cur][c] = ++id;
	  cur = nxt[cur][c];
	  chk[cur] = true;
	}
  }
  cout << id - 1 << '\n';
}
*/
/*
// ÇØ½Ì
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
set<pii> chk;
const int M1 = 1e9 + 7;
const int M2 = 1e5 + 3;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
	int H1 = 0, H2 = 0;
	for (int j = i; j < s.size(); ++j) {
	  int c = s[j] - 'a' + 1;
	  H1 = (27ll * H1 + c) % M1;
	  H2 = (27ll * H2 + c) % M2;
	  chk.insert(pii(H1, H2));
	}
  }
  cout << chk.size() << '\n';
}
*/