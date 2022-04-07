#include<bits/stdc++.h>
using namespace std;
double alpha[27];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(2); cout << fixed;
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++)
        cin >> alpha[i];
    stack<double> stk;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            stk.push(alpha[s[i] - 'A']);
        else {
            double a = stk.top(); stk.pop();
            double b = stk.top(); stk.pop();
            if (s[i] == '*')
                stk.push(b * a);
            else if (s[i] == '+')
                stk.push(b + a);
            else if (s[i] == '-')
                stk.push(b - a);
            else if (s[i] == '/')
                stk.push(b / a);
        }
    }
    cout << stk.top() << '\n';
    return 0;
}