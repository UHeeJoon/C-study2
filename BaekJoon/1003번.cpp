#include<iostream>
using namespace std;
int fibonacci(int num) {
    int fibo[42] = { 1, 0 ,1, };
    for (int i = 3; i <= num + 1; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    return fibo[num];
}
int main() {
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << fibonacci(N) << " " << fibonacci(N + 1) << endl;
    }
}