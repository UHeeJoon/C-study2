#include<bits/stdc++.h>
using namespace std;
int n;
int inorder[100001]; // 중위
int postorder[100001]; // 후위
int memo[100001];
void preorder(int in_s, int in_e, int post_s, int post_e)
{
	if (in_s > in_e || post_s > post_e) return;
	int root = postorder[post_e];
	int idx = memo[root]; // 인오더에서 루트의 인덱스
	int L = idx - in_s;
	cout << root << " ";

	preorder(in_s, idx - 1, post_s, post_s + L - 1);
	preorder(idx + 1, in_e, post_s + L, post_e - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> inorder[i];

	for (int i = 1; i <= n; i++)
		cin >> postorder[i];

	// 인오더에서 해당 값이 어디에 있는지 인덱스 기록
	for (int i = 1; i <= n; i++)
		memo[inorder[i]] = i;

	preorder(1, n, 1, n);
	return 0;
}
/*
#include <iostream>
using namespace std;

int n;
int in_Order[100001];
int post_Order[100001];

// 중위순회배열(s1~e1) / L / Root / R
// 후위순회배열(s2~e2) / L / R / Root
void DFS(int s1, int e1, int s2, int e2) {

	if (s1 > e1 || s2 > e2) return;
	int Root = post_Order[e2];

	int idx = -1;
	for (int i = s1; i <= e1; i++)
	{
		if (in_Order[i] == Root) {
			idx = i;
			break;
		}
	}
	int L_cnt = idx - s1; // Left 개수

	// Root
	cout << Root << " ";
	// L
	DFS(s1, idx - 1, s2, s2 + L_cnt - 1);
	// R
	DFS(idx + 1, e1, s2 + L_cnt, e2 - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> in_Order[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> post_Order[i];
	}

	DFS(1, n, 1, n);
	return 0;
}
*/