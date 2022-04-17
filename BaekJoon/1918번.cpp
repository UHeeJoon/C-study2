#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str; cin >> str;
	stack<char> op;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << str[i];
		}
		else {
			if (str[i] == '+' || str[i] == '-') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/') {
				while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
					cout << op.top();
					op.pop();
				}
				op.push(str[i]);
			}
			else if (str[i] == '(') {
				op.push(str[i]);
			}
			else if (str[i] == ')') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
	return 0;
}
/* // c언어
#pragma warning (disable : 4996)
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char element;
#define MAX_SIZE 100
typedef struct {
	element num[MAX_SIZE];
	int idx;
}Stack;
void stack_init(Stack* stk) {
	stk->idx = -1;
}
int is_empty(Stack* stk) {
	return (stk->idx == -1);
}
int is_full(Stack* stk) {
	return (stk->idx == MAX_SIZE - 1);
}
element pop(Stack* stk) {
	if (is_empty(stk)) {
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
element top(Stack* stk) {
	if (is_empty(stk)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	return stk->num[stk ->idx];
}
int main() {
	// 후위수식 변경
	char str[MAX_SIZE];
	scanf("%s", str);
	Stack op; stack_init(&op);
	int len = (int)strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			printf("%c", str[i]);
		}
		else {
			if (str[i] == '+' || str[i] == '-') {
				while (!is_empty(&op) && top(&op) != '(') {
					printf("%c",pop(&op));
				}
				push(&op, str[i]);
			}
			else if (str[i] == '*' || str[i] == '/') {
				while (!is_empty(&op) && (top(&op) == '*' || top(&op) == '/')) {
					printf("%c", pop(&op));
				}
				push(&op, str[i]);
			}
			else if (str[i] == '(') {
				push(&op, str[i]);
			}
			else if (str[i] == ')') {
				while (!is_empty(&op) && top(&op) != '(') {
					printf("%c", pop(&op));
				}
				pop(&op);
			}
		}
	}
	while (!is_empty(&op)) {
		printf("%c", pop(&op));
	}

	return 0;
}

*/