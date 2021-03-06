#include<iostream>
#include<vector>   
#include<queue>
#include<algorithm>
using namespace std;
const int max_n = 200001;
int visited[max_n], _prev[max_n];
pair<int, int> d[3] = { {1, 1}, {1, -1}, {2, 0} };
int n, k, ret, here, cnt, _next;
vector<int> v;
queue<int> q;
int main() {
    cin >> n >> k;
    visited[n] = 1;
    q.push(n);
    while (q.size()) {
        here = q.front();
        q.pop();
        if (here == k) {
            ret = visited[k];
            break;
        }
        for (int i = 0; i < 3; i++) {
            _next = here * d[i].first + d[i].second;
            if (_next >= max_n || _next < 0 || visited[_next]) continue;
            visited[_next] = visited[here] + 1;
            _prev[_next] = here;
            q.push(_next);
        }
    }
    cout << ret - 1 << '\n';
    for (int i = k; i != n; i = _prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << ' ';
    }
    return 0;
}