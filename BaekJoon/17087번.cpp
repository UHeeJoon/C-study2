#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    FAST_IO;
    int n, s;
    int gcd_tmp = -1;
    cin >> n >> s;
    while (n--)
    {
        int a;
        cin >> a;
        int distance = (s > a) ? (s - a) : (a - s);
        if (gcd_tmp != -1)
        {
            gcd_tmp = gcd(gcd_tmp, distance);
        }
        else
        {
            gcd_tmp = distance;
        }
    }
    cout << gcd_tmp << '\n';
    return 0;
}