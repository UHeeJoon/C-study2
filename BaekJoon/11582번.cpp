#include<bits/stdc++.h>
using namespace std;
#define MAX 1<<21
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int arr[MAX], tmp[MAX];
int n, k;
void my_merge(int s, int e) {
    if (e - s > n / k) return;
    int mid = (s + e) / 2;
    int i = s, j = mid + 1, k = 0;
    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= e) tmp[k++] = arr[j++];
    for (int i = s; i <= e; i++) arr[i] = tmp[i - s];
}

void merge_sort(int s, int e) {
    if (s == e) return;
    int mid = (s + e) / 2;
    merge_sort(s, mid);
    merge_sort(mid + 1, e);
    my_merge(s, e);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}