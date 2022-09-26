#include<bits/stdc++.h>
using namespace std;
#define MAX 1050
//#define INF 2'100'000'000
//#define MOD 1000
typedef long long ll;
int arr[MAX][MAX];
int division(int y, int x, int size) {
	vector<int> v;
	if (size == 1) {
		v.push_back(arr[y][x]);
		v.push_back(arr[y][x + 1]);
		v.push_back(arr[y + 1][x]);
		v.push_back(arr[y + 1][x + 1]);
		sort(v.begin(), v.end());
		return v[2];
	}

	v.push_back(division(y, x, size / 2));
	v.push_back(division(y + size, x, size / 2));
	v.push_back(division(y, x + size, size / 2));
	v.push_back(division(y + size, x + size, size / 2));
	sort(v.begin(), v.end());
	return v[2];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << division(0, 0, n / 2) << '\n';
	return 0;
}