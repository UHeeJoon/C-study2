#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    set<string> str_set;
    for (int idx = 0; idx < N; idx++) {
        string sub; cin >> sub;
        // ����, ã�� �갡 ������ 
        if (str_set.find(sub) == str_set.end()) {
            str_set.insert(sub);
            reverse(sub.begin(), sub.end());
            // �Ӹ�����̸� ����
            if (str_set.find(sub) != str_set.end()) {
                cout << sub.size() << " " << sub[sub.size() / 2];
                return 0;
            }
            str_set.insert(sub);
            // �̹� ����� ���̶�� 
        }
        else {
            cout << sub.size() << " " << sub[sub.size() / 2];
            return 0;
        }
    }
    return 0;
}