#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
void init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		int mid = (start + end) / 2;
		init(a, tree, node * 2, start, mid);
		init(a, tree, node * 2 + 1, mid + 1, end);
		tree[node] = tree[node * 2] * tree[node * 2 + 1];
	}
}
void update(vector<int>& a, vector<int>& tree, int node, int start, int end, int index, int val) {
	if (index < start || index > end)
		return;
	if (start == end) {
		a[index] = val;
		tree[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(a, tree, node * 2, start, mid, index, val);
	update(a, tree, node * 2 + 1, mid + 1, end, index, val);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}
int query(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && end <= right)return tree[node];
	int mid = (start + end) / 2;
	int lsum = query(tree, node * 2, start, mid, left, right);
	int rsum = query(tree, node * 2 + 1, mid + 1, end, left, right);
	return lsum * rsum;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	while (cin >> n >> m) {
		vector<int> a(n);
		int h = (int)ceil(log2(n));
		int tree_size(1 << (h + 1));
		vector<int> tree(tree_size);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] > 0)a[i] = 1;
			else if (a[i] < 0) a[i] = -1;
		}
		init(a, tree, 1, 0, n - 1);
		string ans = "";
		while (m--) {
			char what;
			cin >> what;
			if (what == 'C') {
				int index;
				int val;
				cin >> index >> val;
				if (val > 0)val = 1;
				else if (val < 0) val = -1;
				update(a, tree, 1, 0, n - 1, index - 1, val);
			}
			else if (what == 'P') {
				int left, right;
				cin >> left >> right;
				int multi = query(tree, 1, 0, n - 1, left - 1, right - 1);
				if (multi < 0)ans += "-";
				else if (multi == 0)ans += "0";
				else ans += "+";
			}
		}
		cout << ans << '\n';
	}
	return 0;
}