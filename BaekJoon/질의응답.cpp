#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int _map[51][51];
bool visited[51][51];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
vector<int> virus;
int n, m;
int is_virus() {
    int _max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!_map[i][j])
                return 0;
            else
                _max = max(_max, _map[i][j]);
        }
    }
    return _max;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> _map[i][j];
            if (_map[i][j] == 2)
                virus.push_back(i * 100 + j);
        }
    }

    return 0;
}