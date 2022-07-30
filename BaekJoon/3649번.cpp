#include<bits/stdc++.h>
using namespace std;
int num[1000000 + 10];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x;
	while (cin >> x && !cin.eof()) {
		int n; cin >> n;
		x *= 10'000'000;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		sort(num, num + n);
		int i = 0, j = n - 1;
		int dy = 0, dx = 0;
		int sum = 0;
		while (i < j && i < n && j >= 0) {
			if (num[i] + num[j] < x) i++;
			else if (num[i] + num[j] > x)j--;
			else {
				if (abs(i - j) > sum) {
					sum = abs(i - j);
					dy = i; dx = j;
				}
				i++; j--;
			}
		}
		if (sum == 0)cout << "danger\n";
		else cout << "yes " << num[dy] << ' ' << num[dx] << '\n';
	}
	return 0;
}