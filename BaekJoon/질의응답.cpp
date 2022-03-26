#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    if (n <= 5) cout << n << '\n';
    else
    {
        if ((n - 5) / 4 % 2 == 0)
            cout << 5 - (n - 5) % 4 << '\n';
        else
            cout << 1 + (n - 5) % 4 << '\n';
    }
    return 0;
}