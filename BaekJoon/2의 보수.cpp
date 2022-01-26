#include <iostream>
#include <limits.h>
using namespace std;
int bin[33];
int bin2[33];
int num;
void binary1(int num) {
	int i = 0;
	while (num > 0) {
		bin[i] = num % 2;
		num /= 2;
		i++;
	}
}
void binary2(int num) {
	int i = 0;
	num++;
	num *= -1;
	while (num > 0) {
		bin2[i] = num % 2;
		num /= 2;
		i++;
	}
}
int comp() {
	int cnt = 0;
	for (int i = 0; i < 32; i++) {
		if (bin[i] == bin2[i])
			cnt++;
	}
	return cnt;
}
int main() {
	cin >> num;
	binary1(num);
	binary2(num * -1);
	cout << comp() << "\n";
	return 0;
}