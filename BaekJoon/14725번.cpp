#include<bits/stdc++.h>
using namespace std;
vector<string> v[20];
struct TRIE {
    map<string, TRIE*> _map;
    /* 트라이 트리 만들기 (재귀로 구현) */
    void Insert(vector<string>& foods, int index) {
        if (index == foods.size())
            return;

        if (_map.find(foods[index]) == _map.end())
            _map[foods[index]] = new TRIE();
        _map[foods[index]]->Insert(foods, index + 1);
    }

    void Output(int depth) { // DFS
        for (auto& ch : _map) {
            for (int i = 0; i < depth; ++i) // 깊이 당 -- 한 번 
                cout << "--";
            cout << ch.first << '\n';
            ch.second->Output(depth + 1);
        }
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    TRIE* Root = new TRIE();
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        vector<string> foods(k);
        for (int j = 0; j < k; ++j)
            cin >> foods[j];

        Root->Insert(foods, 0); // 트라이 트리 만들고
    }

    Root->Output(0); // DFS 탐색
    return 0;
}