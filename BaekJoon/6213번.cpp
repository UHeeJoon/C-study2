#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void min_init(vector<int>& a, vector<int>& tree, const int node, const int start, const int end) {
    if (start == end) tree[node] = a[start];
    else {
        min_init(a, tree, node * 2, start, (start + end) / 2);
        min_init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}
void max_init(vector<int>& a, vector<int>& tree, const int node, const int start, const int end) {
    if (start == end) tree[node] = a[start];
    else {
        max_init(a, tree, node * 2, start, (start + end) / 2);
        max_init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}
int min_query(vector<int>& tree, const int node, const int start, const int end, const int left, const int right) {
    if (left > end || right < start) return -1;
    if (left <= start && end <= right)
        return tree[node];
    const int l_min = min_query(tree, node * 2, start, (start + end) / 2, left, right);
    const int r_min = min_query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if (l_min == -1) return r_min;
    else if (r_min == -1) return l_min;
    else return min(l_min, r_min);
}
int max_query(vector<int>& tree, const int node, const int start, const int end, const int left, const int right) {
    if (left > end || right < start) return -1;
    if (left <= start && end <= right)
        return tree[node];
    const int l_min = max_query(tree, node * 2, start, (start + end) / 2, left, right);
    const int r_min = max_query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if (l_min == -1) return r_min;
    else if (r_min == -1) return l_min;
    else return max(l_min, r_min);
}
int main()
{
    FAST_IO;
    int n, m; cin >> n >> m;
    vector<int> a(n);
    const int h = static_cast<int>(ceil(log2(n)));
    const int tree_size = (1 << (h + 1));
    vector<int> min_tree(tree_size);
    vector<int> max_tree(tree_size);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    min_init(a, min_tree, 1, 0, n - 1);
    max_init(a, max_tree, 1, 0, n - 1);
    while (m--) {
        int left, right;
        cin >> left >> right;
        cout << max_query(max_tree, 1, 0, n - 1, left - 1, right - 1) - min_query(min_tree, 1, 0, n - 1, left - 1, right - 1) << '\n';
    }
    return 0;
}