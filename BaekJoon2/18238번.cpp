#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int sum = 0;
	int tmp = 0;
	for (char a : str) {
		int cha = a - 'A';
		if (cha > tmp)cha = min(26 - cha + tmp, cha - tmp);
		else if (cha < tmp)cha = min(26 - tmp + cha, tmp - cha);
		else cha = 0;
		sum += cha;
		tmp = a - 'A';
	}
	cout << sum << '\n';
	return 0;
}