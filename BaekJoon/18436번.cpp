#include<bits/stdc++.h>
using namespace std;
#define MAX 100'000 + 10
int odd[MAX], even[MAX];
int n, m;
void oddInit(int idx, int diff) {
    while (idx <= n + 1) {
        odd[idx] += diff;
        idx += (idx & -idx);
    }
}
void evenInit(int idx, int diff) {
    while (idx <= n + 1) {
        even[idx] += diff;
        idx += (idx & -idx);
    }
}
int oddQuery(int idx) {
    int sum = 0;
    while (idx) {
        sum += odd[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int evenQuery(int idx) {
    int sum = 0;
    while (idx) {
        sum += even[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        if (num & 1)
            oddInit(i, 1);
        else
            evenInit(i, 1);
    }
    cin >> m;
    while (m--) {
        int i, j, x; cin >> i >> j >> x;
        if (i == 1) {
            int odd = oddQuery(j) - oddQuery(j - 1);
            int even = evenQuery(j) - evenQuery(j - 1);
            if (x & 1) {
                if (even) {
                    evenInit(j, -1);
                    oddInit(j, 1);
                }
            }
            else {
                if (odd) {
                    oddInit(j, -1);
                    evenInit(j, 1);
                }
            }
        }
        else if (i == 2)
            cout << evenQuery(x) - evenQuery(j - 1) << '\n';
        else if (i == 3)
            cout << oddQuery(x) - oddQuery(j - 1) << '\n';
    }
    return 0;
}


/*
#include<iostream>
using namespace std;

int N, M, a[100001], q, u, v, tree_size = 1;
int tree[1<<18];

void updateST(int idx, int val)        // count odd
{
    int t;
    if ( (a[idx] & 1)^(val & 1) )
    {
        t = (val & 1)?1:-1;
        a[idx] = val;                // update a[] when state(even,odd) is changed
        idx += tree_size;
        while (idx >= 1)
        {
            tree[idx] += t;
            idx >>= 1;
        }
    }
}

int cnt_odd(int l, int r)
{
    int cnt = 0;
    l += tree_size, r += tree_size;

    while (l <= r)
    {
        if (l & 1) cnt += tree[l++];
        if (~r & 1) cnt += tree[r--];
        l >>= 1, r >>= 1;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    while (tree_size < N) tree_size <<= 1;
    for (int i = 0; i < N; ++i)
    {
        cin >> u;
        updateST(i, u);
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> q >> u >> v;
        if (q == 1) updateST(u-1, v);
        else if (q == 2) cout << (v-u+1)-cnt_odd(u-1, v-1) << "\n";
        else cout << cnt_odd(u-1, v-1) << "\n";
    }
    return 0;
}
*/