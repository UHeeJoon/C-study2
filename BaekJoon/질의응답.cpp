#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int Adrian(char answer[], int index)
{
	switch (index % 3)
	{
	case 0:
		if (answer[index] == 'A') return 1;
		break;
	case 1:
		if (answer[index] == 'B') return 1;
		break;
	case 2:
		if (answer[index] == 'C') return 1;
		break;
	}
}

int Bruno(char answer[], int index)
{
	switch (index % 4)
	{
	case 0:
		if (answer[index] == 'B') return 1;
		break;
	case 1:
		if (answer[index] == 'A') return 1;
		break;
	case 2:
		if (answer[index] == 'B') return 1;
		break;
	case 3:
		if (answer[index] == 'C') return 1;
		break;
	}
}

int Goran(char answer[], int index)
{
	switch (index % 6)
	{
	case 0:
		if (answer[index] == 'C') return 1;
		break;
	case 1:
		if (answer[index] == 'C') return 1;
		break;
	case 2:
		if (answer[index] == 'A') return 1;
		break;
	case 3:
		if (answer[index] == 'A') return 1;
		break;
	case 4:
		if (answer[index] == 'B') return 1;
		break;
	case 5:
		if (answer[index] == 'B') return 1;
		break;
	}
}


int main()
{
	int i, n, a = 0, b = 0, c = 0, max = 0;
	char answer[110];

	scanf("%d", &n);
	scanf("%s", answer);

	for (i = 0; i < n; i++)
	{
		if (Adrian(answer, i) == 1) a++;
		if (Bruno(answer, i) == 1) b++;
		if (Goran(answer, i) == 1) c++;
	}

	if (a < b)
	{
		if (b < c) max = c;
		else max = b;
	}

	else
	{
		if (a < c) max = c;
		else max = a;
	}

	printf("%d\n", max);
	if (max == a) printf("Adrian\n");
	if (max == b) printf("Bruno\n");
	if (max == c) printf("Goran\n");

	return 0;
}