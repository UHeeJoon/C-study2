#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> s;
        if (s.length() > 10)
            cout << s.front() << int(s.length() - 2) << s.back() << '\n';
        else
            cout << s << '\n';
    }
    return 0;
}