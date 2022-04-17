#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct {
	int top;
	char arr[SIZE];
} stack;

void push(stack* m, char ch) {
	m->arr[++(m->top)] = ch;
}

void stack_init(stack* a, stack* op) {
	a->top = -1;
	op->top = -1;
	memset(a->arr, 0, sizeof(a->arr));
	memset(op->arr, 0, sizeof(op->arr));
}

char pop(stack* m) {
	return m->arr[(m->top)--];
}

int is_empty(stack* m) {
	return m->top == -1;
}

int main() {
	stack a, op;
	char* s = "5*2+2-3*2";
	stack_init(&a, &op);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] != '*' && s[i] != '/' && s[i] != '-' && s[i] != '+') {
			push(&a, s[i]);
		}
		else {
			if (op.top == -1) {
				push(&op, s[i]);
			}
			else {
				if (s[i] == '+' || s[i] == '-') {
					push(&a, pop(&op));
					push(&op, s[i]);
				}
				else { // s[i] == '*' || s[i] == '/'
					if (op.arr[op.top] == '/' || op.arr[op.top] == '*') {
						push(&a, pop(&op));
						push(&op, s[i]);
					}
					else {
						push(&op, s[i]);
					}
				}
			}
		}
	}

	while (!is_empty(&op)) {
		push(&a, pop(&op));
	}
	for (int i = 0; i < strlen(a.arr); i++) {
		printf("%c", a.arr[i]);
	}
}
/*
#pragma warning (disable : 4996)
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char element;
typedef double element2;
#define MAX_SIZE 100
typedef struct {
	element num[MAX_SIZE];
	int idx;
}Stack;
typedef struct {
	element2 num[MAX_SIZE];
	int idx;
}Stack2;
void stack_init(Stack* stk) {
	stk->idx = -1;
}
void stack_init2(Stack2* stk) {
	stk->idx = -1;
}
int is_empty(Stack* stk) {
	return (stk->idx == -1);
}
int is_empty2(Stack2* stk) {
	return (stk->idx == -1);
}
int is_full(Stack* stk) {
	return (stk->idx == MAX_SIZE - 1);
}
int is_full2(Stack2* stk) {
	return (stk->idx == MAX_SIZE - 1);
}
element pop(Stack* stk) {
	if (is_empty(stk)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	return stk->num[stk->idx--];
}
element2 pop2(Stack2* stk) {
	if (is_empty2(stk)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	return stk->num[stk->idx--];
}
void push(Stack* stk, element ele) {
	if (is_full(stk)) {
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	stk->num[++stk->idx] = ele;
}
void push2(Stack2* stk, element2 ele) {
	if (is_full2(stk)) {
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	stk->num[++stk->idx] = ele;
}
element top(Stack* stk) {
	if (is_empty(stk)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	return stk->num[stk ->idx];
}
element2 top2(Stack2* stk) {
	if (is_empty2(stk)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	return stk->num[stk->idx];
}

int main() {
	// 후위수식 변경
	char str[MAX_SIZE];
	char str2[MAX_SIZE] = { 0, };
	scanf("%s", str);
	Stack op; stack_init(&op);
	int len = (int)strlen(str);
	int len2 = (int)strlen(str2);
	for (int i = 0; i < len; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			printf("%c", str[i]);
			str2[len2++] = str[i];
		}
		else {
			if (str[i] == '+' || str[i] == '-') {
				while (!is_empty(&op) && top(&op) != '(') {
					str2[len2++] = top(&op);
					printf("%c",pop(&op));
				}
				push(&op, str[i]);
			}
			else if (str[i] == '*' || str[i] == '/') {
				while (!is_empty(&op) && (top(&op) == '*' || top(&op) == '/')) {
					str2[len2++] = top(&op);
					printf("%c", pop(&op));
				}
				push(&op, str[i]);
			}
			else if (str[i] == '(') {
				push(&op, str[i]);
			}
			else if (str[i] == ')') {
				while (!is_empty(&op) && top(&op) != '(') {
					str2[len2++] = top(&op);
					printf("%c", pop(&op));
				}
				pop(&op);
			}
		}
	}
	while (!is_empty(&op)) {
		str2[len2++] = top(&op);
		printf("%c", pop(&op));
	}
	printf("\n");

	// 후위 수식 계산
	Stack2 cal; stack_init2(&cal);
	for (int i = 0; i < len2; i++) {
		if (str2[i] >= '0' && str2[i] <= '9')
			push2(&cal, str2[i] - '0');
		else {
			double first = pop2(&cal);
			double second = pop2(&cal);
			printf("%.1lf\t", second);
			printf("%.1lf\t", first);
			if (str2[i] == '*') 
				push2(&cal, second * first);
			else if (str2[i] == '+') 
				push2(&cal, second + first);		
			else if (str2[i] == '-') 
				push2(&cal, second - first);			
			else if (str2[i] == '/') 
				push2(&cal, second / first);			
			printf("%c\t=%.1lf	스택에 push\n",str2[i], top2(&cal));
		}
	}
	printf("결과: %.1lf\n", pop2(&cal));
	return 0;
}
*/