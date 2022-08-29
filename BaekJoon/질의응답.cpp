#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
#define INF 2147483647
int n, lis[MAX], len, num;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        if (*lowerPos == 0) len++;
        *lowerPos = num;
    }
    cout << len << '\n';
	return 0;
}
