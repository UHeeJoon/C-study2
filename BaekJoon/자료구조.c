#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	int array[100];
} stack;

void stack_init(stack* s) {
	s->top = -1;
}

int empty(stack* s) {
	return (s->top == -1);
}

void push(stack* s, int a) {
	s->array[++(s->top)] = a;
}

int top(stack* s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		return s->array[s->top];
	}
}

int size(stack* s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		return (s->top + 1);
	}
}

int pop(stack* s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		return s->array[(s->top)--];
	}
}

int main() {
	int n = 0;
	stack s;
	stack_init(&s);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char s[100];
		int a = 0;
		scanf("%s", s);
		if (strcmp(s, "push") == 0) {
			scanf("%d", &a);
			push(&s, a);
		}
		else if (strcmp(s, "top") == 0) {
			printf("%d", top(&s));
		}
		else if (strcmp(s, "size") == 0) {
			printf("%d", size(&s));
		}
		else if (strcmp(s, "empty") == 0) {
			if (empty(&s) == 1) {
				printf("1");
			}
			else {
				printf("0");
			}
		}
		else { // pop 일 때
			printf("%d", pop(&s));
		}
	}
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