#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) {
            cout << '@';
        }
        cout << '\n';
    }
    for (int l = 0; l < 3; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << '@';
            }
            cout << '\n';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) {
            cout << '@';
        }
        cout << '\n';
    }
    return 0;
}