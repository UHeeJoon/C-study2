#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a = 0, b;
    cin >> n;
    n -= 1;
    while (1) {
        a++;
        if (a * a + a == n)break;
    }
    cout << a << '\n';
	return 0;
}
