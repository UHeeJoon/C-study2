#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef string::size_type st;
vector<int> getPi(const string& p) {
    const st m = p.size();
    int j = 0;
    vector<int> pi(m, 0);
    for (st i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}
vector<int> kmp(const string& s, const string& p) {
    vector<int> ans;
    const auto pi = getPi(p);
    const st n = s.size(), m = p.size();
    st j = 0;
    for (st i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(static_cast<int>(i - m + 1));
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return ans;
}
int main()
{
    FAST_IO;
    string s, p;
    getline(cin, s);
    getline(cin, p);
    const auto matched = kmp(s, p);
    cout << matched.size() << '\n';
    for (const auto i : matched)
        cout << i + 1;
    return 0;
}