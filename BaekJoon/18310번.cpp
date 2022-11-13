#include<bits/stdc++.h>
using namespace std;
#define MAX 200'000 + 10
int n;
int arr[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << arr[(n - 1) / 2] << '\n';
	return 0;
}