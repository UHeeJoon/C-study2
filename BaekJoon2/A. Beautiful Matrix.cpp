#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char a[6][6] = { 0, };
	int y = 3, x = 3;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> a[i][j];
			if (a[i][j] == '1')
				y -= i, x -= j;
		}
	}
	y = y < 0 ? (y * -1) : y;
	x = x < 0 ? (x * -1) : x;
	cout << x + y << '\n';
	return 0;
}