#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k, n, w; cin >> k >> n >> w;
    long long sum = 0;
    for (int i = 1; i <= w; i++)
        sum += i;
    sum *= k;
    cout << (sum - n < 0 ? 0 : sum - n) << '\n';
    return 0;
}