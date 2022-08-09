#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
int n, k, arr[5000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	cout << arr[k - 1] << '\n';
	return 0;
}