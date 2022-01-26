#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ll S, sum = 0;
    int num = 1, cnt = 0;
    cin >> S;
    while (1) {
        sum += num;
        cnt++;
        if (sum > S) {
            cnt--;
            break;
        }
        num++;
    }
    cout << cnt << '\n';
    return 0;
}