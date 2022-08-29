#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
#define INF 2147483647
int n, lis[MAX], len, num;
//pair<int, int> ans[MAX];
//stack<int> stk;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        //int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if (*lowerPos == 0) len++;
        *lowerPos = num;
        //ans[i].first = _pos;
        //ans[i].second = num;
    }
    cout << len << '\n';
    //for (int i = n - 1; i >= 0; i--) {
    //    if (ans[i].first == len - 1) {
    //        stk.push(ans[i].second); len--;
    //    }
    //}
    //while (stk.size()) {
    //    cout << stk.top() << ' '; stk.pop();
    //}
    return 0;
}