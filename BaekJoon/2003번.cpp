#include<bits/stdc++.h>
using namespace std;
int num[10001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) cin >> num[i];
	int i = 0, j = 1;
	while (i <= j && j <= n) {
		int tmp = accumulate(num + i, num + j, 0);
		if (tmp < m) j++;
		else if (tmp == m) {
			cnt++;
			i++; j++;
		}
		else
			i++;
	}
	cout << cnt << '\n';
	return 0;
}
/*
#include <iostream>

using namespace std;

int n, m;
int count = 0;

int main() {
	cin >> n >> m;

	int a[n + 1];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int start = 0, end = 0;
	int result = a[0];

	while (start <= end && end < n) {
		if (result < m) {
			result += a[++end];
		}
		else if (result == m) {
			count++;
			result += a[++end];
		}
		else if (result > m) {
			result -= a[start++];

			if (start > end) {
				end = start;
				result = a[start];
			}
		}
	}

	cout << count << '\n';
}
*/