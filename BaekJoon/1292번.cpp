#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b; cin >> a >> b;
	int arr[1001] = { 0, }, cnt = 1, tmp = 0;
	for (int i = 1; i <= b; i++) {
		if (cnt <= tmp)
			tmp = 0, cnt += 1;

		arr[i] = cnt + arr[i - 1];
		tmp++;
	}
	cout << arr[b] - arr[a - 1] << '\n';
	return 0;
}