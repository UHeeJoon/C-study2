#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
void normalize(vector<int>& num){
    num.push_back(0);
    for (int i = 0; i < num.size() - 1; i++){
        if (num[i] < 0){
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else{
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while (num.size() > 1 && num.back() == 0)
        num.pop_back();
}
vector<int> multiply(const vector<int>& a, const vector<int>& b){
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += (a[i] * b[j]);
    normalize(c);
    return c;
}
void addTo(vector<int>& a, const vector<int>& b, int k){
    int length = b.size();
    a.resize(max(a.size() + 1, b.size() + k));
    for (int i = 0; i < length; i++)
        a[i + k] += b[i]; //이렇게 함으로써 굳이 다른 vector를 선언하지 않아도 되고 간편해졌다
    for (int i = 0; i < a.size(); i++){
        if (a[i] >= 10){
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    }
}
void subFrom(vector<int>& a, const vector<int>& b){
    int length = b.size();
    a.resize(max(a.size() + 1, b.size()) + 1);
    for (int i = 0; i < length; i++)
        a[i] -= b[i];
    for (int i = 0; i < a.size(); i++){
        if (a[i] < 0){
            a[i] += 10;
            a[i + 1] -= 1;
        }
    }
}
vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
    int an = a.size(), bn = b.size();
    if (an < bn)
        return karatsuba(b, a);
    if (an == 0 || bn == 0)
        return vector<int>();
    if (an <= 5)
        return multiply(a, b);
    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);
    vector<int> result;
    addTo(result, z0, 0);
    addTo(result, z1, half);
    addTo(result, z2, half + half);
    return result;

}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> a, b, result;
    string number;
    cin >> number;
    for (int i = number.size() - 1; i >= 0; i--)
        a.push_back(number[i] - '0');
    cin >> number;
    for (int i = number.size() - 1; i >= 0; i--)
        b.push_back(number[i] - '0');
    result = karatsuba(a, b);
    while (1) {
        if (result[result.size() - 1] == 0) 
            result.pop_back();
        else
            break;
    }
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
    return 0;
}