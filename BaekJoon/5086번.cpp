#include<iostream>
using namespace std;
int num1 = 1, num2 = 1;
void check() {
	if (num1 % num2 == 0) {
		cout << "multiple\n";
		return;
	}
	else if (num2 % num1 == 0) {
		cout << "factor\n";
		return;
	}
	cout << "neither\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		cin >> num1 >> num2;
		if (num1 == 0 && num2 == 0) break;
		check();
	}
	return 0;
}