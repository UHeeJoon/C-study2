#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, sum(0), sum2(0), num[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (!tmp)
			sum2 += num[i];
	}
	cout << sum << '\n' << sum2 << '\n';
	return 0;
}