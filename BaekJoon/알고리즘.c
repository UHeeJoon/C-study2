#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char name[100];
}element;
typedef struct ListNode{
	element data; struct ListNode* link;
} ListNode;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element values) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = values;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	if (head == NULL) return; 
	print_list(head->link);
	printf("%s\n", head->data.name);
}
void print_list_reverse(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%s\n", p->data.name);
	}
	printf("\n");
}
int main() {
	ListNode* head = NULL;
	element input;
	printf("이번학기 수강과목을 입력하세요! (모두 입력후에는 \"끝\"을 입력하세요)\n");
	while (1) {
		fgets(input.name, sizeof(input.name), stdin);
		input.name[(int)strlen(input.name) - 1] = '\0';
		if (!strcmp(input.name, "끝\0")) {
			break;
		}
		head = insert_first(head, input);
	}
	printf("\n");
	printf("입력된 순서 : \n");
	print_list(head);
	printf("\n");
	printf("입력된 순서의 역순으로 출력 : \n");
	print_list_reverse(head);

	return 0;
}


