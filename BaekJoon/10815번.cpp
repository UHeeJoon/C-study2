#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		int low = 0, high = n - 1;
		bool flag = false;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (v[mid] == num) {
				flag = true;
				break;
			}
			else if (v[mid] < num)
				low = mid + 1;
			else
				high = mid - 1;
		}
		cout << (flag ? 1 : 0) << ' ';
	}
	cout << '\n';
	return 0;
}