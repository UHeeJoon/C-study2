#include<bits/stdc++.h>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    set<char> st;
    string s; cin >> s;
    for (int i = 0; i < s.length(); i++)
        st.insert(s[i]);
    cout << (st.size() & 1 ? "IGNORE HIM!\n" : "CHAT WITH HER!\n");
    return 0;
}