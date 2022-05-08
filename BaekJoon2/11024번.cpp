#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        int sum = 0, tmp = 0;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                tmp = tmp * 10 + (s[i] - '0');
            else {
                sum += tmp;
                tmp = 0;
            }
        }
        cout << sum + tmp << '\n';
    }
    return 0;
}