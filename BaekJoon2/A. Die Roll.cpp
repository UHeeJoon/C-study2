#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int y, w, t;
    cin >> y >> w;
    t = 6 - (y > w ? y : w) + 1;
    if ((t + 6) % 6 == 0)
        cout << t / 6 << '/' << 6 / 6 << '\n';
    else if ((t + 6) % 2 == 0)
        cout << t / 2 << '/' << 6 / 2 << '\n';
    else if ((t + 6) % 3 == 0)
        cout << t / 3 << '/' << 6 / 3 << '\n';
    else
        cout << t << '/' << 6 << '\n';
    return 0;
}