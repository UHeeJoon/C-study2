#pragma warning(disable: 4996)
#include<stdio.h>
int main(int argc, char *argv[]) {


	return 0;
}
/*
// 1935 후위 표기식2
#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>

typedef struct stack
{
	int top;
	double data[100];
} Stack;

double pop(Stack* s)
{
	return s->data[s->top--];
}

void push(Stack* s, double item)
{
	s->data[++s->top] = item;
}

double calculate(double a, double b, char c)
{
	switch (c)
	{
	case '+':
		return b + a;
	case '-':
		return b - a;
	case '/':
		return b / a;
	case '*':
		return b * a;
	}
}

int main(void)
{
	int n;
	double tmp;
	double num[26];
	char str[100];
	Stack s;
	s.top = 0;

	scanf("%d", &n);
	scanf("%s", str);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &num[i]);
	}

	for (int i = 0; i < strlen(str); i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			push(&s, (num[str[i] - 'A']));
		}
		else
		{
			double a = pop(&s);
			double b = pop(&s);
			push(&s, calculate(a, b, str[i]));
		}
	}
	printf("%.2f", pop(&s));
}
*/