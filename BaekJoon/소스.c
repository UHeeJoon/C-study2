#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
  

		char tarr[10][50];

		printf("������ �迭 ���ڿ� �Է�\n");
		for (int i = 0; i < 3; i++)
		{
			printf("10�� �̳��� ���ڿ��� �Է����ּ��� : ");
			scanf_s("%s", tarr[i]);
		}

		printf("\n������ �迭 ���ڿ� ���\n");
		for (int i = 0; i < 3; i++)
		{
			printf("%s\n", tarr[i]);
		}


    return 0;
}