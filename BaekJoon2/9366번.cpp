#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << "Case #" << i << ": ";
        if (a[0] == a[1] && a[1] == a[2])
            cout << "equilateral\n";
        else if (a[1] == a[0] || a[1] == a[2] || a[2] == a[0]) {
            if (a[2] < a[0] + a[1])
                cout << "isosceles\n";
            else
                cout << "invalid!\n";
        }
        else {
            if (a[2] < a[0] + a[1])
                cout << "scalene\n";
            else
                cout << "invalid!\n";
        }
    }
    return 0;
}