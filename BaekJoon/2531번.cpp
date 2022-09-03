#include<bits/stdc++.h>
using namespace std;
#define MAX 30050
//#define INF 2147483647
//#define MOD 1'000'000'007
//typedef long long ll;

int susi[MAX];
int visited[MAX / 10];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, d, k, c; cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) {
        cin >> susi[i];
    }
    int left = 0, right = k - 1;
    int cnt = 0, _max = 0;
    for (int i = left; i <= right; i++) {
        if (!visited[susi[i]])
            cnt++;
        visited[susi[i]]++;
    }
    _max = visited[c] ? cnt : cnt + 1;

    while (right != k - 2) {
        visited[susi[left]]--;
        if (!visited[susi[left]])
            cnt--;
        left = (left + 1) % n;

        right = (right + 1) % n;
        if (visited[susi[right]] == 0) {
            cnt++;
        }
        visited[susi[right]]++;
        //cout << left << ' ' << right <<  ' ' << cnt << '\n';
        _max = max(_max, visited[c] ? cnt : cnt + 1);

    }
    cout << _max << '\n';
    return 0;
}