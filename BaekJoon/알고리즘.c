#pragma warning(disable:4996)

#include<stdio.h>
int sum(int n) {
	int _sum = 0;
	for (int i = 1; i <= n; i += 2)
		_sum += i;
	return _sum;
}
int main() {
	printf("%d", sum(10));
	return 0;
}