#include<bits/stdc++.h>
using namespace std;
//#define MAX 1'000'010
//#define INF 60'000'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
void min_init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
    if (start == end) tree[node] = a[start];
    else {
        min_init(a, tree, node * 2, start, (start + end) / 2);
        min_init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}
void max_init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
    if (start == end) tree[node] = a[start];
    else {
        max_init(a, tree, node * 2, start, (start + end) / 2);
        max_init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}
int min_query(vector<int>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return -1;
    if (left <= start && end <= right)
        return tree[node];
    int lmin = min_query(tree, node * 2, start, (start + end) / 2, left, right);
    int rmin = min_query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if (lmin == -1) return rmin;
    else if (rmin == -1) return lmin;
    else return min(lmin, rmin);
}
int max_query(vector<int>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return -1;
    if (left <= start && end <= right)
        return tree[node];
    int lmin = max_query(tree, node * 2, start, (start + end) / 2, left, right);
    int rmin = max_query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if (lmin == -1) return rmin;
    else if (rmin == -1) return lmin;
    else return max(lmin, rmin);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
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
        cout << min_query(min_tree, 1, 0, n - 1, left - 1, right - 1) << ' ';
        cout << max_query(max_tree, 1, 0, n - 1, left - 1, right - 1) << '\n';
    }
    return 0;
} 