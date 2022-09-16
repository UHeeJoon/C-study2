#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
int n, s;
int arr[41];
map<int, int> subsum;
long long cnt;
void rightSeq(int mid, int sum) {
    if (mid == n) {
        subsum[sum]++;
        return;
    }

    rightSeq(mid + 1, sum + arr[mid]);
    rightSeq(mid + 1, sum);
}
void leftSeq(int st, int sum) {
    if (st == n / 2) {
        cnt += subsum[s - sum];
        return;
    }

    leftSeq(st + 1, sum + arr[st]);
    leftSeq(st + 1, sum);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rightSeq(n / 2, 0);
    leftSeq(0, 0);

    if (!s) cout << cnt - 1;
    else cout << cnt;

	return 0;
}

