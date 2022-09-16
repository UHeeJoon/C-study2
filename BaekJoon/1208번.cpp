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


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <tuple>
//
//int n, m, k, t;
//
//using namespace std;
//
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//
//	cin >> n >> m;
//	vector<int> a(n);
//	for (int i = 0; i < n; ++i) cin >> a[i];
//
//	k = n / 2;    //0~n/2
//	n = n - k;    //n/2~n
//
//	vector<int> sub1(1 << k);
//	for (int i = 0; i < (1 << k); ++i) {
//		for (int j = 0; j < k; ++j) {
//			if (i & (1 << j)) {
//				sub1[i] += a[j];
//			}
//		}
//	}
//
//	vector<int> sub2(1 << n);
//	for (int i = 0; i < (1 << n); ++i) {
//		for (int j = 0; j < n; ++j) {
//			if (i & (1 << j)) {
//				sub2[i] += a[k + j];
//			}
//		}
//	}
//
//	sort(sub1.begin(), sub1.end());
//	sort(sub2.rbegin(), sub2.rend());
//
//
//	long long ans = 0;
//	int l = 0, r = 0;
//	k = sub1.size();
//	n = sub2.size();
//	int i = 0;
//	int j = 0;
//	while (i < k && j < n) {
//		if (sub1[i] + sub2[j] == m) {
//			long long c1 = 1;
//			long long c2 = 1;
//			i += 1;
//			j += 1;
//			while (i < k && sub1[i] == sub1[i - 1]) {
//				c1 += 1;
//				i += 1;
//			}
//			while (j < n && sub2[j] == sub2[j - 1]) {
//				c2 += 1;
//				j += 1;
//			}
//			ans += (c1 * c2);
//
//		}
//		else if (sub1[i] + sub2[j] < m) i += 1;
//		else j += 1;
//	}
//
//	if (m == 0) ans -= 1;
//	cout << ans << '\n';
//
//	return 0;
//}