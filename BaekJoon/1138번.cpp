#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, left;
    int ary[11] = { 0, };
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> left;
        for (int j = 1; j <= N; j++) {
            if (!left && !ary[j]) {
                ary[j] = i;
                break;
            }
            else if (!ary[j]) { left--; }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ary[i] << " ";
    }
    return 0;
}