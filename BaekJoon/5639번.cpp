#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}
void postorder(Node* node) {
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->data << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Node* root = NULL;
	int val;
	while (cin >> val) {
		root = insert(root, val);
	}
	postorder(root);
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int tree[10000];
void postOrder(int start, int end) {
	if (start >= end) {
		return;
	}
	if (start == end - 1) {
		cout << tree[start] << '\n';
		return;
	}
	int idx = start + 1;
	while (idx < end) {
		if (tree[start] < tree[idx]) {
			break;
		}
		idx++;
	}
	postOrder(start + 1, idx);
	postOrder(idx, end);
	cout << tree[start] << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	int inputIdx = 0;
	while (cin >> num) {
		tree[inputIdx++] = num;
	}
	postOrder(0, inputIdx);
	return 0;
}
*/