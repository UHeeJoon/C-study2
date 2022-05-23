#include<bits/stdc++.h>
using namespace std;
int num[10010];
int n, m;
void binary_search() {
	int low = 0, high = num[n - 1], sum = 0;
	while (low <= high) {
		sum = 0;
		int mid = (low + high) / 2;
		for (int i = 0; i < n; i++) {
			if (num[i] < mid)
				sum += num[i];
			else
				sum += mid;
		}
		if (sum <= m)
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << high << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	cin >> m;
	sort(num, num + n);
	binary_search();
	return 0;
}