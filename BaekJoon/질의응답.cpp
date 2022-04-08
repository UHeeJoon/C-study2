#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int result[2] = { 0, };
    for (int i = 0; i < 2; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        result[i] = a * 6 + b * 3 + c * 2 + d + e * 2;
    }
    cout << result[0] << ' ' << result[1] << '\n';
    return 0;   
}
