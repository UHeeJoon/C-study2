#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    deque<int> dq;
    string s;
    int t; cin >> t;
    while (t--) {
        cin >> s;
        if (s[0] == 'p') {
            if (s[1] == 'o') {
                if (s[4] == 'f') {
                    if (dq.empty())
                        cout << -1 << '\n';
                    else {
                        cout << dq.front() << '\n';
                        dq.pop_front();
                    }
                }
                else {
                    if (dq.empty())
                        cout << -1 << '\n';
                    else {
                        cout << dq.back() << '\n';
                        dq.pop_back();
                    }
                }
            }
            else if (s[1] == 'u') {
                int tmp; cin >> tmp;
                if (s[5] == 'f') {
                    dq.push_front(tmp);
                }
                else {
                    dq.push_back(tmp);
                }
            }
        }
        else if (s[0] == 's') {
            cout << dq.size() << '\n';
        }
        else if (s[0] == 'e') {
            cout << (dq.empty() ? 1 : 0) << '\n';
        }
        else if (s[0] == 'f') {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.front() << '\n';
        }
        else {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.back() << '\n';
        }
    }
    return 0;
}