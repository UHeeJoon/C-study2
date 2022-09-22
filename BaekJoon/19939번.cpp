#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    int sum = 0, i = 1;
    for (i = 1; i <= k; i++) {
        sum += i;
    }
    n -= sum;
    if (n < 0) {
        cout << -1 << '\n';
    }
    else {
        if (n % k == 0)
            cout << k - 1 << '\n';
        else if (n % k != 0)
            cout << k << '\n';
    }
    return 0;
}