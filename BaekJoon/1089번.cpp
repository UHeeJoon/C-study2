#include<bits/stdc++.h>
using namespace std;
string str[6], num[11][6] = {
    {"###","#.#","#.#","#.#","###"},
    {"..#","..#","..#","..#","..#"},
    {"###","..#","###","#..","###"},
    {"###","..#","###","..#","###"},
    {"#.#","#.#","###","..#","..#"},
    {"###","#..","###","..#","###"},
    {"###","#..","###","#.#","###"},
    {"###","..#","..#","..#","..#"},
    {"###","#.#","###","#.#","###"},
    {"###","#.#","###","..#","###"}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(5); cout << fixed;
    int n; cin >> n;
    for (int i = 0; i < 5; i++) {
        cin >> str[i];
    }
    double ans = 0, g = 1;
    for (int i = n - 1; i >= 0; i--) {
        int c = 0, cnt = 0;
        for (int j = 0; j < 10; j++) {
            bool flag = true;
            for (int k = 0; k < 5; k++)
                for (int l = 0; l < 3; l++)
                    if (num[j][k][l] == '.' && str[k][4 * i + l] == '#')
                        flag = false;
            if (flag) {
                cnt++;
                c += j;
            }
        }
        if (cnt == 0)
            return cout << -1 << '\n', 0;
        ans += g * c / cnt;
        g *= 10;
    }
    cout << ans << '\n';
    return 0;
}