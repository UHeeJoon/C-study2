#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int arr[100010], arr2[100010];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n = 1; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i] >> arr2[i];
	sort(arr, arr + n);
	sort(arr2, arr2 + n);
	cout << (arr[n - 1] - arr[0]) * (arr2[n - 1] - arr2[0]) << '\n';
	return 0;
}
