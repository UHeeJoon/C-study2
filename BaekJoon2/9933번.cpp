#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    set<string> str_set;
    for (int idx = 0; idx < N; idx++) {
        string sub; cin >> sub;
        // 만약, 찾는 얘가 없으면 
        if (str_set.find(sub) == str_set.end()) {
            str_set.insert(sub);
            reverse(sub.begin(), sub.end());
            // 팰린드롬이면 종료
            if (str_set.find(sub) != str_set.end()) {
                cout << sub.size() << " " << sub[sub.size() / 2];
                return 0;
            }
            str_set.insert(sub);
            // 이미 저장된 값이라면 
        }
        else {
            cout << sub.size() << " " << sub[sub.size() / 2];
            return 0;
        }
    }
    return 0;
}