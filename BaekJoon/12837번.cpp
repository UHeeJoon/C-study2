#include<bits/stdc++.h>
using namespace std;
#define MAX 1'000'000 + 10
typedef long long ll;
ll day[MAX];
int n, Q;
void update(int idx, int diff) {
    while (idx <= n + 1) {
        day[idx] += diff;
        idx += (idx & -idx);
    }
}
ll sum(int idx) {
    ll _sum = 0;
    while (idx) {
        _sum += day[idx];
        idx -= (idx & -idx);
    }
    return _sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> Q;
    while (Q--) {
        int what; cin >> what;
        if (what == 1) {
            int p, x; cin >> p >> x;
            update(p, x);
        }
        else {
            int p, q; cin >> p >> q;
            cout << sum(q) - sum(p - 1) << '\n';
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, q;
ll tree[4000006];
int v1, v2, v3;

void init(int idx, int start, int end) {
    if (start == end)
    {
        tree[idx] = 0;
        return;
    }
    int mid = (start + end) / 2;
    init(2 * idx, start, mid);
    init(2 * idx + 1, mid + 1, end);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

ll query(int idx, int l, int r, int start, int end) {
    if (start > r || end < l)
    {
        return 0;
    }
    if (l <= start && end <= r)
    {
        return tree[idx];
    }
    int mid = (start + end) / 2;
    ll ls = query(2 * idx, l, r, start, mid);
    ll rs = query(2 * idx + 1, l, r, mid + 1, end);
    return ls + rs;
}

void add(int idx, int target, int start, int end, int v) {
    if (start > target || end < target)
    {
        return;
    }
    if (start == end)
    {
        tree[idx] += v;
        return;
    }
    int mid = (start + end) / 2;
    add(2 * idx, target, start, mid, v);
    add(2 * idx + 1, target, mid + 1, end, v);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    init(1, 1, n);
    for (int i = 0; i < q; i++)
    {
        cin >> v1 >> v2 >> v3;
        if (v1 == 1)
        {
            add(1, v2, 1, n, v3);
        }
        else
        {
            cout << query(1, v2, v3, 1, n) << "\n";
        }
    }
    return 0;
}

*/