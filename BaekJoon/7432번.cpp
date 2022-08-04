#include<bits/stdc++.h>
using namespace std;
struct TRIE {
    map<string, TRIE*> _map;
    /* Ʈ���� Ʈ�� ����� (��ͷ� ����) */
    void Insert(vector<string>& foods, int index) {
        if (index == foods.size())
            return;

        if (_map.find(foods[index]) == _map.end())
            _map[foods[index]] = new TRIE();
        _map[foods[index]]->Insert(foods, index + 1);
    }

    void Find(int depth) { // DFS
        for (auto& ch : _map) {
            for (int i = 0; i < depth; i++) {
                cout << ' ';
            }
            cout << ch.first << '\n';
            ch.second->Find(depth + 1);
        }
    }
};
vector<string> split(string s) { // \�������� ���ڿ� �ɰ���
    vector<string> ret;
    int pos = 0;
    string token = "";
    while ((pos = (int)s.find('\\')) != string::npos) {
        token = s.substr(0, pos);
        ret.push_back(token);
        s.erase(0, pos + 1);
    }
    ret.push_back(s);
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    TRIE* Root = new TRIE();
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        vector<string> str = split(s);
        Root->Insert(str, 0); // Ʈ���� Ʈ�� �����
    }
    Root->Find(0); // DFS Ž��
    return 0;
}