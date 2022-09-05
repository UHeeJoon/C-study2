#include<bits/stdc++.h>
using namespace std;
#define MAX 10010
#define INF 60'000'000'000
//#define MOD 1'000'000'007
typedef long long ll;
int arr[MAX];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
    }
    ll left = 0, right = INF;
    ll sum = 0;
    if (n <= m) {
        cout << n << '\n';
        return 0;
    }
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll ridePerson = m;
        for (int i = 1; i <= m; i++) {
            ridePerson += mid / arr[i];
        }
        if (ridePerson >= n) {
            sum = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    ll ridePerson = m;
    for (int i = 1; i <= m; i++)
        ridePerson += ((sum - 1) / arr[i]);
    for (int i = 1; i <= m; i++) {
        if ((sum % arr[i]) == 0)ridePerson++;
        if (ridePerson == n) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}