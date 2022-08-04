#include<bits/stdc++.h>
using namespace std;
struct TRIE {
	TRIE* Node[26];
	TRIE() { // 생성자
		for (int i = 0; i < 26; i++) Node[i] = NULL;
	}
	~TRIE() { // 소멸자
		for (int i = 0; i < 26; i++) if (Node[i])delete Node[i];
	}
	void insert(char* str) { // 삽입
		// 문자열 마지막 == NULL
		if (*str == '\0') return; 

		// 문자열 a~z -> 숫자로 0~26
		int Cur = *str - 'a';

		// 삽입할 문자열의 노드 생성 
		if (Node[Cur] == NULL) Node[Cur] = new TRIE();

		// 다음 문자 삽입
		Node[Cur]->insert(str + 1);
	}
	bool find(char* str) { // 탐색
		// 마지막까지 탐색 마치면 true
		if (*str == '\0') return true;
		int Cur = *str - 'a';

		// 탐색 중간에 NULL이면 접두사 아님
		if (Node[Cur] == NULL) return false;
		// 다음 문자 탐색
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