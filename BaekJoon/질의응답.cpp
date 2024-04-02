#pragma warning(disable : 4996)
//https://www.acmicpc.net/problem/18428
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main()
{
	FAST_IO;
	int n, k; cin >> n >> k;
	vector<int> v(n);
	vector<int> v2(n - 1);
	for (int& el : v) {
		cin >> el;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++) {
		v2[i] = v[i + 1] - v[i];
	}
	sort(v2.begin(), v2.end());
	int sum = 0;
	for (int i = 0; i < n - k; i++) {
		sum += v2[i];
	}
	cout << sum << '\n';
	return 0;
}