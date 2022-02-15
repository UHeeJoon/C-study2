#include<iostream>
using namespace std;
int main() {
	int num;
	num = 0;
	while (num < 100) {
		int sum, One, Try = 0, new_num;
		new_num = num;
		do {
			sum = (new_num / 10 + new_num % 10) % 10;
			One = new_num % 10;
			new_num = One * 10 + sum;
			Try += 1;
		} while (new_num != num);
		cout << num << "\t" << Try << "\t";

		int cnt = 0;
		int new_n = num;
		while (1) {
			cnt = cnt++;
			new_n = ((new_n / 10) + (new_n % 10)) % 10 + (new_n % 10) * 10;
			if (new_n == num) break;
		}
		cout << cnt << "\n";;
		num++;
	}
}
