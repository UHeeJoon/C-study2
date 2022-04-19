#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a[3]; cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int tmp = a[1] - a[0], tmp2 = a[2] - a[1];
	if (tmp == tmp2)
		cout << a[2] + tmp << '\n';
	else {
		if (tmp > tmp2)
			cout << a[0] + tmp - tmp2 << '\n';
		else
			cout << a[1] + tmp2 - tmp << '\n';
	}
	return 0;
}