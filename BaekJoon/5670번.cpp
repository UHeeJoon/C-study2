#include<bits/stdc++.h>
using namespace std;
char arr[100010][88];
bool ini;
int n, ans;
struct TRIE {
    bool vaild;
    bool exist;
    int branch;
    TRIE* node[26];
    TRIE() :vaild(false), exist(false), branch(0) {
        for (int i = 0; i < 26; i++) node[i] = 0;
    }
    ~TRIE() {
        for (int i = 0; i < 26; i++)
            if (node[i]) delete node[i];
    }
    void add(char* str) {
        if (*str == 0) vaild = true;
        else {
            int pos = *str - 'a';
            if (node[pos] == NULL) {
                branch++; node[pos] = new TRIE();
            }
            exist = true;
            node[pos]->add(str + 1);
        }
    }
    void check(char* str) {
        if (*str == 0) return;
        if (ini) {
            ans++; ini = false;
        }
        else {
            if (branch >= 2) ans++;
            else if (vaild) ans++;
        }
        int pos = *str - 'a';
        node[pos]->check(str + 1);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(2);
    cout << fixed;
    int n;
    while (cin >> n && !cin.eof()) {
        TRIE* root = new TRIE();
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            root->add(arr[i]);
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            ini = true;
            ans = 0;
            root->check(arr[i]);
            total += ans;
        }
        cout << (double)total / n << '\n';
        delete root;
    }
    return 0;
}