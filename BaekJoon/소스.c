#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
  

		char tarr[10][50];

		printf("이차원 배열 문자열 입력\n");
		for (int i = 0; i < 3; i++)
		{
			printf("10자 이내의 문자열을 입력해주세요 : ");
			scanf_s("%s", tarr[i]);
		}

		printf("\n이차원 배열 문자열 출력\n");
		for (int i = 0; i < 3; i++)
		{
			printf("%s\n", tarr[i]);
		}


    return 0;
}