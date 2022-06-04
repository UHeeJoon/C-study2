#include<bits/stdc++.h>
using namespace std;
const int MAX = 500 + 1;
vector<int> friends[MAX];
bool friendsList[MAX];
void findFriends(int nodeNum) {
    for (int i = 0; i < friends[nodeNum].size(); i++) {
        int next = friends[nodeNum][i];
        friendsList[next] = true;
    }
    if (nodeNum == 1) {
        for (int i = 0; i < friends[nodeNum].size(); i++) {
            int next = friends[nodeNum][i];
            findFriends(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    findFriends(1);
    int cnt = 0;
    for (int i = 2; i <= N; i++)
        if (friendsList[i])
            cnt++;
    cout << cnt << '\n';
    return 0;
}

/*
#include <iostream>
using namespace std;

int n, m;
const int MAX = 501;
int map[MAX][MAX];
bool visited[MAX];
bool sFriend[MAX];
int ans = 0;
void count() {
    for (int i = 2; i <= n; i++) {
        if (map[1][i] == 1) {
            visited[i] = true;
            sFriend[i] = true;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (sFriend[i]) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j]) {
                    visited[j] = true;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (visited[i]) {
            ans++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    count();
    cout << ans << '\n';
    return 0;
}

*/