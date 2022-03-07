#pragma warning(disable:4996)
#include <bits/stdc++.h>
using namespace std;
long long s, e, ret, cnt[100001], n, num[100001];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", num + i);
    }
    while (e < n) {
        if (!cnt[num[e]]) {
            cnt[num[e]]++;
            e++;
        }
        else {
            ret += (e - s);
            cnt[num[s]]--;
            s++;
        }
    }
    ret += (long long)(e - s) * (e - s + 1) / 2;
    printf("%lld\n", ret);
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100000];
bool visited[100001];

int main() {
    // freopen("input.txt", "r", stdin);

    memset(visited, 0, sizeof(visited));

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long ret = 0;
    int right = 0;
    for (int left = 0; left < n; left++) {
        while (right < n && !visited[arr[right]]) {
            visited[arr[right]] = true;
            right++;
        }

        ret += (right - left);
        visited[arr[left]] = false;
    }

    printf("%lld", ret);

    return 0;
}
*/