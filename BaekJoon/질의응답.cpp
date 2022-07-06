#pragma warning(disable: 4996)
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