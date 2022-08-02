#include<bits/stdc++.h>
using namespace std;
int DP[22][103];
int w[22];
int v[22];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100; j++) {
            if (j - w[i] > 0)
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[n][100] << '\n';
    return 0;
}
/* 1차원 배열 활용
#include<bits/stdc++.h>
using namespace std;
int DP[103];
int w[22];
int v[22];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 100; j > w[i]; j--) {
            DP[j] = max(DP[j], DP[j - w[i]] + v[i]);
        }
    }
    cout << DP[100] << '\n';
    return 0;
}
*/

/* 재귀 활용
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int maxhappy = -1;
int N;

void go(vector<int> &p,vector<int> &h,int number,int happy,int power) {
    if (power < 1) return;
    if (number >= N) {
        maxhappy = max(maxhappy, happy);
        return;
    }
    go(p, h, number + 1, happy, power);
    go(p, h, number + 1, happy + h[number],power - p[number]);
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> N;
    vector<int> power(N);
    vector<int> happy(N);
    for (auto& x : power) cin >> x;
    for (auto& x : happy) cin >> x;
    go(power,happy,0,0,100);
    cout << maxhappy;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int maxhappy = -1;
int N;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> N;
    vector<int> power(N);
    vector<int> happy(N);
    for (auto& x : power) cin >> x;
    for (auto& x : happy) cin >> x;

    for (int i = 0; i < (1 << N); i++) {
        int happysum = 0;
        int power2 = 100;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                happysum += happy[j];
                power2 -= power[j];
            }
        }
        if (power2 >= 1) maxhappy = max(maxhappy, happysum);
    }
    cout << maxhappy;
}
*/