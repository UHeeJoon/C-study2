#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char num1[9], num2[9];
    int arr[17];
    cin >> num1 >> num2;
    for (int i = 0; i < 8; ++i) {
        arr[i * 2] = num1[i] - '0';
        arr[i * 2 + 1] = num2[i] - '0';
    }
    for (int i = 15; i >= 2; --i) {
        for (int j = 0; j < i; ++j) {
            arr[j] = (arr[j] + arr[j + 1]) % 10;
        }
    }
    cout << arr[0] << arr[1] << '\n';
	return 0;
}