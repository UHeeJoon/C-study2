#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char c = 0, op;
	int num, sum;
	cin >> num;
	sum = num;
	while (1) {
		cin >> op;
		if (op == '=') break;
		cin >> num;
		if (op == '+') sum += num;
		else if (op == '-')sum -= num;
		else if (op == '*')sum *= num;
		else if (op == '/')sum /= num;
	}
	cout << sum << '\n';
	return 0;
}