#include<bits/stdc++.h>
using namespace std;
#define N_MAX 1000 + 1 
#define STR_MAX 50 + 1

int str_cmp(const string& A, const string& B) {
    const int a_size = A.size(), B_size = B.size();
    if (a_size != B_size) return a_size < B_size;
    
    int A_sum = 0, B_sum = 0;
    for (int idx = 0; idx < a_size; idx++) {
        if ('0' <= A[idx] && A[idx] <= '9')    A_sum += A[idx] - '0';
        if ('0' <= B[idx] && B[idx] <= '9')    B_sum += B[idx] - '0';
    }
    if (A_sum != B_sum) return A_sum < B_sum;
    
    return A < B;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    string str_input[N_MAX];
    for (int n_idx = 0; n_idx < N; n_idx++)
        cin >> str_input[n_idx];
    sort(str_input, str_input + N, str_cmp);

    for (int n_idx = 0; n_idx < N; n_idx++)
        cout << str_input[n_idx] << "\n";
    return 0;
}