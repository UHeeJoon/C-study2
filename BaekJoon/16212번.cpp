#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int& el : v) {
        cin >> el;
    }
    sort(v.begin(), v.end());
    for (const int el : v) {
        cout << el << ' ';
    }
    cout << '\n';
    return 0;
}