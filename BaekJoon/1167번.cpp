#include<bits/stdc++.h>
using namespace std;
int visited[100002] = { 0 };
vector<pair<int, int>> node[100002];
int ans = 0;
int end_point = 0;
void dfs(int point, int length) {
    if (visited[point]) return;
    visited[point] = 1;
    if (ans < length) {
        ans = length;
        end_point = point;
    }
    for (int i = 0; i < node[point].size(); i++)
        dfs(node[point][i].first, length + node[point][i].second);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int parent, child, length;
    while (n--) {
        cin >> parent;
        while (1) {
            cin >> child;
            if (child == -1) break;
            cin >> length;
            node[parent].push_back(make_pair(child, length));
            node[child].push_back(make_pair(parent, length));
        }
    }
    dfs(1, 0);
    ans = 0;
    memset(visited, 0, sizeof(visited));
    dfs(end_point, 0);
    cout << ans << '\n';
    return 0;
}