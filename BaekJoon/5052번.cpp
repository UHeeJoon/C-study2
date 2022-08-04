#include<bits/stdc++.h>
using namespace std;
char input[10000][11];

struct TRIE {
	bool Finish;
	TRIE* Node[10];
	TRIE() {
		Finish = false;
		for (int i = 0; i < 10; i++) {
			Node[i] = NULL;
		}
	}
	void insert(char* str) {
		if (*str == '\0') {
			Finish = true;
			return;
		}
		int Cur = *str - '0';
		if (Node[Cur] == NULL) Node[Cur] = new TRIE();
		Node[Cur]->insert(str + 1);
	}

	bool find(char* str) {
		//������ �����ϸ� return false
		if (*str == '\0') {
			return false;
		}
		//�߰��� finish�� ������ �ϰ��� x (� ��ȭ��ȣ�� �ٸ� ��ȭ��ȣ�� ���ξ �Ǹ�)
		if (Finish == true)
			return true;

		int Cur = *str - '0';
		if (Node[Cur] == NULL) return false;
		return Node[Cur]->find(str + 1);
	}
};
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t, n; cin >> t;
	while (t--) {
		cin >> n;
		TRIE* Root = new TRIE();
		for (int i = 0; i < n; i++) {
			cin >> input[i];
			Root->insert(input[i]);
		}
		int i;
		for (i = 0; i < n; i++) {
			if (Root->find(input[i])) {
				cout << "NO\n";
				break;
			}
		}
		if (i == n)
			cout << "YES\n";
	}
	return 0;
}
/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

bool solve()
{
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	for(int i = 0; i < n-1; i++)
		if(v[i] == v[i+1].substr(0, v[i].size()))
			return false;
	return true;
}
int main()
{
	fastio;
	int tc;
	cin >> tc;
	while(tc--)
		cout << (solve() ? "YES\n" : "NO\n");
	return 0;
}
*/