#include<bits/stdc++.h>
using namespace std;
int arr[110];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		if (!arr[num]) arr[num] = i;
		else {
			int tmp = n;
			while (tmp != num) {
				arr[tmp] = arr[tmp - 1];
				tmp--;
			}
			arr[num] = i;
		}
	}
	for (int i = n - 1; i >= 0; i--)
		cout << arr[i] << ' ';
	cout << '\n';
	return 0;
}