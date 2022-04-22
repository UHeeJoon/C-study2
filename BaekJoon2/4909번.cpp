#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		double a[6], sum = 0;
		for (int i = 0; i < 6; i++) 
			cin >> a[i];
		if (!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5])
			break;
		sort(a, a + 6);
		for (int i = 1; i < 5; i++)
			sum += a[i];
		cout << sum / 4 << '\n';
	}
	return 0;
}