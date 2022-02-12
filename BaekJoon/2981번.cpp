#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, temp, cnt, num[501];
int gcd(int a, int b) {
	if (b)
		return gcd(b, a % b);
	return a;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> num[i];
    sort(num, num + n);

    temp = num[1] - num[0];
    for (int i = 2; i < n; i++)
        temp = gcd(temp, num[i] - num[i - 1]);

    memset(num, 0, sizeof(num));

    for (int i = 2; i * i <= temp; i++)
        if (temp % i == 0) {
            num[cnt++] = i;
            if (i != temp / i) num[cnt++] = temp / i;
        }
    num[cnt++] = temp;
    sort(num, num + cnt);
    for (int i = 0; i < cnt; i++)
        if (num[i] != 1)
            cout << num[i] << " ";
    return 0;
}