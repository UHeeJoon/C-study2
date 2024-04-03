#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
void merge(vector<ll>& v, vector<ll>& tmp, int start, int mid, int end, ll& result) {
    int k = start;
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) {
            tmp[k] = v[i];
            i++;
            k++;
        }
        else {
            tmp[k] = v[j];
            result += j - k;
            j++;
            k++;
        }
    }

    if (i <= mid) {
        for (int t = i; t <= mid; t++) {
            tmp[k] = v[t];
            k++;
        }
    }
    else {
        for (int t = j; t <= end; t++) {
            tmp[k] = v[t];
            k++;
        }
    }

    for (int t = start; t <= end; t++) {
        v[t] = tmp[t];
    }
}
void mergeSort(vector<ll>& v, vector<ll>& tmp, int start, int end, ll& result) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(v, tmp, start, mid, result);
        mergeSort(v, tmp, mid + 1, end, result);
        merge(v, tmp, start, mid, end, result);
    }
}
int main()
{
    FAST_IO;
    int n; cin >> n;
    vector<ll> v(n);
    vector<ll> tmp(n);
    ll result = 0;
    for (ll& a : v) {
        cin >> a;
    }
    mergeSort(v, tmp, 0, n - 1, result);
    cout << result << '\n';
    return 0;
}