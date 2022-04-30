#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num[210] = { 0, };
    int n; cin >> n;
    while (n--) {
        int tmp; cin >> tmp;
        num[tmp + 100] = 1;
    }
    bool flag = false;
    for (int i = 0; i < 201; i++) {
        if (num[i] != 0) {
            if (flag) {
                cout << i - 100 << '\n';
                return 0;
            }
            flag = true;
        }
    }
    cout << "NO\n";
    return 0;
}