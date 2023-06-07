#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
    FAST_IO;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        int cnt = 1, pre = 1;
        for (int j = 1; j < tmp; j++) {
            cnt += (pre *= 2);
        }
        cout << cnt << '\n';
    }
    return 0;
}