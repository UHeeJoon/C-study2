#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 2147483647
void init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
    if (start == end) tree[node] = a[start];
    else {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}
int query(vector<int>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return -1;
    if (left <= start && end <= right)
        return tree[node];
    int lmin = query(tree, node * 2, start, (start + end) / 2, left, right);
    int rmin = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if (lmin == -1) return rmin;
    else if (rmin == -1) return lmin;
    else return min(lmin, rmin);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    vector<int> tree(tree_size);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n - 1);

    while (m--) {
        int left, right;
        cin >> left >> right;
        cout << query(tree, 1, 0, n - 1, left - 1, right - 1) << '\n';
    }
    return 0;
}