#include<bits/stdc++.h>
#define MAX 14
using namespace std;
int lotto[MAX], combi[MAX], k;
void dfs(int start, int end) {
    if (end == 6) {
        for (int i = 0; i < 6; i++) {
            cout << combi[i] << ' '; 
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < k; i++) {     
        combi[end] = lotto[i];
        dfs(i + 1, end + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> k && k) {
        for (int i = 0; i < k; i++) 
            cin >> lotto[i];
        dfs(0, 0);
        cout << '\n';
    }
    return 0;
}