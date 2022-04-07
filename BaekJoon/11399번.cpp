#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int* num = new int[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    int sum = 0, tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += num[i];
        sum += tmp;
    }
    cout << sum << '\n';
    delete[] num;
    return 0;
}