#include<stdio.h>
#define MAX 2147483647
int ft_is_prime(int nb) {
	if (nb < 2)return 0;
	//double s = 0, t = 0;
	//s  = nb / 2;
	//while (s  != t){
	//	t  = s;
	//	s  = ((nb  / t) + t) / 2;
	//}
	int left = 2, right = 46340;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nb % mid == 0)return 0;
		else if () {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return 1;

}

int main() {
	for (int i = 2; i <= 100; i++) {
		printf("%d %d\n",i, ft_is_prime(i));
		//printf("%d\n", i);
	}


}