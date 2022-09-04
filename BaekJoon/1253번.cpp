#include<bits/stdc++.h>
using namespace std;
#define MAX 2004
//#define INF 2147483647
//#define MOD 1'000'000'007
//typedef long long ll;

int arr[MAX];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (arr[left] + arr[right] == arr[i]) {
                if (left != i && right != i) {
                    cnt++;
                    break;
                }
                else if (left == i)left++;
                else if (right == i)right--;
            }
            else if (arr[left] + arr[right] < arr[i])
                left++;
            else right--;
        }
    }
    cout << cnt << '\n';
    return 0;
}