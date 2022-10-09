#include<bits/stdc++.h>
using namespace std;
#define MAX 1'000'000 + 10
typedef long long ll;
ll A[MAX];
ll _sum[MAX];
int n, m;
void Modify(int idx, int k) {
	while (idx <= n + 1) {
		_sum[idx] += k;
		idx += (idx & -idx);
	}
}
ll Sum(int idx) {
	ll sum = 0;
	while (idx) {
		sum += _sum[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	while (m--) {
		int what; cin >> what;
		if (what == 0) {
			int i, j; cin >> i >> j;
			if (i > j)swap(i, j);
			cout << Sum(j) - Sum(i - 1) << '\n';
		}
		else if (what == 1) {
			int i, k; cin >> i >> k;
			Modify(i, k - A[i]);
			A[i] = k;
		}
	}
	return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll a[1000006];
ll tree[4000006];
int v1, v2, v3;
ll query(int idx, int l, int r, int start, int end) {
    if (start > r || end < l)
    {
        return 0;
    }
    else if (l <= start && end <= r)
    {
        return tree[idx];
    }
    int mid = (start + end) / 2;
    ll ls = query(2 * idx, l, r, start, mid);
    ll rs = query(2 * idx + 1, l, r, mid + 1, end);
    return ls + rs;
}

void upd(int idx, int target, int start, int end, ll v) {
    if (start > target || end < target)
    {
        return;
    }
    if (start == end)
    {
        a[target] = tree[idx] = v;
        return;
    }
    int mid = (start + end) / 2;
    upd(2 * idx, target, start, mid, v);
    upd(2 * idx + 1, target, mid + 1, end, v);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> v3;
        if (v1 == 0)
        {
            if (v2 > v3)
            {
                swap(v2, v3);
            }
            cout << query(1, v2 - 1, v3 - 1, 0, n - 1) << "\n";
        }
        else
        {
            upd(1, v2 - 1, 0, n - 1, v3);
        }
    }
    return 0;
}

*/