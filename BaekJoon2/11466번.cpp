#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(3); cout << fixed;
    double h, w, answer;
    cin >> h >> w;
    if (h > w) {
        double tmp = h;
        h = w;
        w = tmp;
    }
    if (h * 3 < w) answer = h;
    else if (h * 1.5 < w) answer = w / 3;
    else answer = h / 2;
    cout << answer << '\n';
    return 0;
}