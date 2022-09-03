#include<bits/stdc++.h>
using namespace std;
#define MAX 200004
//#define INF 2147483647
#define MOD 1'000'000'007
typedef long long ll;
int n, value;
ll ret = 1, _prev;
vector<ll> tree_cnt(MAX, 0), tree_sum(MAX, 0);
ll _sum(vector<ll>& tree, int value) {
    ll _ret = 0;
    int i = value;
    while (i) {
        _ret += tree[i];
        i -= (i & -i);
    }
    return _ret;
}
ll sum(vector<ll>& tree, int s, int e) {
    if (s > e) return 0;
    return (_sum(tree, e) - _sum(tree, s - 1));
}

void update(vector<ll>& tree, int x, ll value) {
    int i = x;
    while (i <= MAX) {
        tree[i] += value;
        i += (i & -i);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> value; value++;
        if (i != 1) {
            ll left = value * sum(tree_cnt, 1, value - 1) - sum(tree_sum, 1, value - 1);
            ll right = sum(tree_sum, value + 1, MAX - 1) - value * sum(tree_cnt, value + 1, MAX - 1);
            ret *= (left + right) % MOD;
            ret %= MOD;
        }
        update(tree_cnt, value, 1);
        update(tree_sum, value, value);
    }
    cout << ret << "\n";
    return 0;
}