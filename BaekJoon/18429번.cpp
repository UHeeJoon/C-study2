#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int n, k;
int kit[9];
bool chk[9];
int cnt = 0;
void DFS(int day, int cur) {
    if (day == n - 1) {
        if (cur < 500) {
            return;
        }
        else {
            cnt++;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!chk[i] && cur - k + kit[i] >= 500) {
            chk[i] = true;
            DFS(day + 1, cur - k + kit[i]);
            chk[i] = false;
        }
    }
}
int main()
{
    FAST_IO;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> kit[i];
    }
    DFS(0, 500);
    cout << cnt << '\n';
    return 0;
}