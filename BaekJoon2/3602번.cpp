#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int b, w; cin >> b >> w;
	int _min = min(b, w);
	int  tmp = (int)sqrt(_min * 2 + 1);
	if (b == 0 && w == 0)
		cout << "Impossible ";
	else {
		if (tmp % 2 == 0)
			cout << tmp << ' ';
		else {
			if (b + w < tmp * tmp)
				cout << tmp - 1 << ' ';
			else
				cout << tmp << ' ';
		}
	}
	return 0;
}