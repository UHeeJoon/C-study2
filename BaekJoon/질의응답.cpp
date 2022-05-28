#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num[3] = { 0, };
	for (int i = 0; i < 3; i++)
		cin >> num[i];
	sort(num, num + 3);
	for (int i = 0; i < 3; i++) {
		char a; cin >> a;
		if (a == 'A')
			cout << num[0] << ' ';
		else if (a == 'B')
			cout << num[1] << ' ';
		else
			cout << num[2] << ' ';
	}
	cout << '\n';
	return 0;
}
