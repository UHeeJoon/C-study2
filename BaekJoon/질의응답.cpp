#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
    string A = { 0 }, B = { 0 }, C;
    cin >> A >> B;
    int len, sum, ten = 0, al = 0, bl = 0;
    if (B.length() > A.length()) len = B.length();
    else len = A.length();
    for (int i = 1; i <= len; i++) {
        sum = 0;
        al = A.length() - i, bl = B.length() - i;
        if (al >= 0 && al < (int)A.length()) sum += A[al] - '0';
        if (bl >= 0 && bl < (int)B.length()) sum += B[bl] - '0';
        sum += ten;
        if (sum >= 10)
            ten = 1;
        else
            ten = 0;
        C += to_string(sum % 10);
        if (sum / 10 != 0 && i == len)
            C += to_string(sum / 10);
    }
    reverse(C.begin(), C.end());
    cout << C;
    return 0;
}