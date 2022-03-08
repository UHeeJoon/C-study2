#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        queue<pair<int, int>> q;
        priority_queue <int> pq;
        int n, m, cnt = 0;; cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            q.push({ i,tmp });
            pq.push(tmp);
        }
        while (!q.empty()) {
            int index = q.front().first;
            int importance = q.front().second;
            q.pop();
            if (pq.top() == importance) {
                pq.pop();
                cnt++;
                if (index == m) {
                    cout << cnt << '\n';
                    break;
                }
            }
            else
                q.push({ index,importance });
        }
    }
    return 0;
}