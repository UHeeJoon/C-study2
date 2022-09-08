#include<bits/stdc++.h>
using namespace std;
#define MAX 100'010
#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
struct Node { int num = INF, idx = INF; };
bool operator < (const Node& a, const Node& b) {
    if (a.num == b.num) return a.idx < b.idx;
    return a.num < b.num;
}

Node query(vector<Node>& tree, int start, int end, int node, int left, int right) {
    if (left > end || start > right) return { INF, INF };
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return min(query(tree, start, mid, node * 2, left, right), query(tree, mid + 1, end, node * 2 + 1, left, right));
}

Node update(vector<Node>& tree, int start, int end, int node, int index, int y) {
    if (index < start || index > end) return tree[node];
    if (start == end) return tree[node] = { y, index };
    int mid = (start + end) / 2;
    return tree[node] = min(
        update(tree, start, mid, node * 2, index, y),
        update(tree, mid + 1, end, node * 2 + 1, index, y)
    );
}

Node init(vector<Node>& tree, vector<int>& v, int start, int end, int node) {
    if (start == end) return tree[node] = { v[start], start };
    int mid = (start + end) / 2;
    return tree[node] = min(init(tree, v, start, mid, node * 2), init(tree, v, mid + 1, end, node * 2 + 1));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int tree_size = (int)ceil(log2(n));
    tree_size = 1 << (tree_size + 1);
    vector<Node> tree(tree_size);
    init(tree, v, 0, n - 1, 1);
    int m; cin >> m;¤º
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(tree, 0, n - 1, 1, b - 1, c);
        }
        else {
            cout << query(tree, 0, n - 1, 1, b - 1, c - 1).idx + 1 << '\n';
        }

    }
    return 0;
}