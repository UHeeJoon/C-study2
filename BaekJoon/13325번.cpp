#include<bits/stdc++.h>
using namespace std;
#define MAX (1<<21) + 1
int tree[MAX];
int k, ret;
int Binary_Search(int node) {
    if (node * 2 >= k) {
        ret += tree[node];
        return tree[node];
    }
    else {
        int left = Binary_Search(node * 2);
        int right = Binary_Search(node * 2 + 1);
        ret += abs(left - right) + tree[node];
        return tree[node] + max(left, right);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k;
    k = 1 << (k + 1);
    for (int i = 2; i < k; i++) {
        cin >> tree[i];
    }
    Binary_Search(1);
    cout << ret << '\n';
    return 0;
}