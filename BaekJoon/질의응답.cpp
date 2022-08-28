#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
#define MAX 510
#define INF 2147483647
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int start, end;
		cin >> start >> end;
		int cnt = 0;
		for (int i = start; i <= end; i++) {
			int tmp = i;
			while (tmp) {
				if (tmp % 10 == 0)
					cnt++;
				tmp /= 10;
			}
		}
		if (start == 0) cnt++;
		cout << cnt << '\n';
	}
	return 0;
}
