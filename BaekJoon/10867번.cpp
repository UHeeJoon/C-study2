#include<bits/stdc++.h>
using namespace std;
int arr[2010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		arr[tmp + 1000] = 1;
	}
	for (int i = 0; i < 2005; i++) {
		if (arr[i])
			cout << i - 1000 << ' ';
	}
	cout << '\n';
	return 0;
}