#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int a[3]; cin >> a[0] >> a[1] >> a[2];
		if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;
		if (a[1] - a[0] == a[2] - a[1])
			cout << "AP " << a[2] + a[2] - a[1] << '\n';
		if (a[0] * a[2] == a[1] * a[1])
			cout << "GP " << a[2] * (a[2] / a[1]) << '\n';
	}
	return 0;
}