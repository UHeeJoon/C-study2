#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;
TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	if (temp == NULL) exit(1);
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key)node->left = insert_node(node->left, key);
	else if (key > node->key) node->right = insert_node(node->right, key);
	return node;
}
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->left = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
int Sum(TreeNode* root) {
	if (root == NULL) return 0;
	int sum = root->key;
	return sum + Sum(root->left) + Sum(root->right);

}
int main() {
	TreeNode* root = NULL;
	root = insert_node(root, 1);
	root = insert_node(root, 2);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	root = insert_node(root, 5);
	root = insert_node(root, 6);
	root = insert_node(root, 8);
	printf("node�� ���� : %d �Դϴ�.\n", Sum(root));
	return 0;
}





//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 50
//typedef struct {
//	int id;
//	int arrival_time;
//	int service_time;
//}element;
//typedef struct {
//	element data[MAX_QUEUE_SIZE];
//	int front, rear;
//}QueueType;
//void error(char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType* q) {
//	q->front = q->rear = 0;
//}
//int is_empty(QueueType* q) {
//	return (q->front == q->rear);
//}
//int is_full(QueueType* q) {
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//void enqueue(QueueType* q, element item) {
//	if (is_full(q))error("ť�� ��ȭ�����Դϴ�");
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->data[q->rear] = item;
//}
//element dequeue(QueueType* q) {
//	if (is_empty(q))error("ť�� ��������Դϴ�");
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//	return q->data[q->front];
//}
//element peek(QueueType* q) {
//	if (is_empty(q)) error("ť�� ��������Դϴ�");
//	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
//}
//int main() {
//	int minutes = 10;
//	int total_wait = 0;
//	int total_customers = 0;
//	int service_time = 0, service_time2 = 0;
//	int service_customer, service_customer2 = 0;
//	int aCounter = 0, bCounter = 0;
//	QueueType queue;
//	init_queue(&queue);
//	srand(time(NULL));
//	for (int clock = 0; clock < minutes; clock++) {
//		printf("����ð�=%d\n", clock);
//		if ((rand() % 10) < 7) {
//			element customer;
//			customer.id = total_customers++;
//			customer.arrival_time = clock;
//			customer.service_time = rand() % 3 + 1;
//			enqueue(&queue, customer);
//			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð� = %d��\n",
//				customer.id, customer.arrival_time, customer.service_time);
//		}
//		if (service_time > 0) {
//			printf("�� %d�� aâ������ ����ó�����Դϴ�. \n", service_customer);
//			service_time--;
//			if (service_time == 0)
//				aCounter = 0;
//		}
//		else if(aCounter == 0) {
//			if (!is_empty(&queue)) {
//				element customer = dequeue(&queue);
//				service_customer = customer.id;
//				service_time = customer.service_time;
//				printf("�� %d�� %d�п� a â������ ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
//					customer.id, clock, clock - customer.arrival_time);
//				total_wait += clock - customer.arrival_time;
//				aCounter = 1;
//			}
//		}
//		if (service_time2 > 0) {
//			printf("�� %d�� bâ������ ����ó�����Դϴ�. \n", service_customer2);
//			service_time2--;
//			if (service_time2 == 0)
//				bCounter = 0;
//		}
//		else if (bCounter == 0) {
//			if (!is_empty(&queue)) {
//				element customer = dequeue(&queue);
//				service_customer2 = customer.id;
//				service_time2 = customer.service_time;
//				printf("�� %d�� %d�п� bâ������ ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
//					customer.id, clock, clock - customer.arrival_time);
//				total_wait += clock - customer.arrival_time;
//				bCounter = 1;
//			}
//		}
//	}
//	printf("��ü ��� �ð�=%d�� \n", total_wait);
//	return 0;
//}




//#pragma warning(disable:4996)
//#include <stdio.h>
//#include<stdlib.h>
//typedef int element;
//typedef struct ListNode {
//	element data;
//	struct ListNode* link;
//}ListNode;
//void error(char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//ListNode* insert_first(ListNode* head, element value) {
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	p->data = value;
//	p->link = head;
//	head = p;
//	return head;
//}
//ListNode* insert(ListNode* head, ListNode* pre, element value) {
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	p->data = value;
//	p -> link = pre->link;
//	pre->link = p;
//	return head;
//}
//ListNode* delete_first(ListNode* head) {
//	ListNode* removed;
//	if (head == NULL) return NULL;
//	removed = head;
//	head = removed -> link;
//	free(removed);
//	return head;
//}
//ListNode* delete(ListNode* head, ListNode* pre) {
//	ListNode* removed;
//	removed = pre->link;
//	pre->link = removed->link;
//	free(removed);
//	return head;
//}
//void sum(ListNode *head) {
//	int sum = 0;
//	for (ListNode* i = head; i != NULL; i = i->link)
//		sum += i->data;
//	printf("���� ����Ʈ�� ������ ��: %d\n", sum);
//}
//void find_node(ListNode* head, element value) {
//	int cnt = 0;
//	for (ListNode* i = head; i != NULL; i = i->link)
//		if (i->data == value)
//			cnt++;
//	printf("%d�� ���� ����Ʈ���� %d�� ��Ÿ���ϴ�\n", value, cnt);
//}
//void find_max_min(ListNode* head) {
//	int _max =-987654321, _min = 987654321;
//	for (ListNode* i = head; i != NULL; i = i->link) {
//		if (i->data > _max)
//			_max = i->data;
//		if (i->data < _min)
//			_min = i->data;
//	}
//	printf("�ִ� ��: %d , �ּ� ��: %d\n", _max, _min);
//}
//int main() {
//	ListNode *head = NULL;
//	printf("����� ���� : ");
//	int cnt; scanf("%d", &cnt);
//	for (int i = 1; i <= cnt; i++) {
//		int tmp;
//		printf("��� #%d ������ : ", i);
//		scanf("%d", &tmp);
//		head = insert_first(head, tmp);
//	}
//	sum(head);
//	int _find = 0;
//	printf("Ž���� ���� �Է��Ͻÿ�: ");
//	scanf("%d", &_find);
//	find_node(head, _find);
//	find_max_min(head);
//}

//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 5
//typedef int element;
//typedef struct {
//	element data[MAX_QUEUE_SIZE];
//	int front, rear;
//}QueueType;
//void error(char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//void init_queue(QueueType* q) {
//	q->front = 0, q->rear = -1;
//	// rear�� -1�� �����Ͽ� index 0������ ����
//}
//int is_empty(QueueType* q) {
//	if (q->front == -1) return 1; // -1�� �� ����
//	int rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	return (q->front == rear);
//}
//int is_full(QueueType* q) {
//	if (q->rear == -1)	return 0; // -1�� �� ����
//	return ((q->rear + 2) % MAX_QUEUE_SIZE == q->front);
//	// front ==1, rear ==0 �� ���� ��Ȳ ���� ���� rear + 2
//}
//void enqueue(QueueType* q, element item) {
//	if (is_full(q)) { error("ť�� ��ȭ�����Դϴ�"); }
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // ���Ե� index
//	q->data[q->rear] = item;
//}
//element dequeue(QueueType* q) {
//	if (is_empty(q)) { error("ť�� ��������Դϴ�"); }
//	int front = q->front;	// ���� index
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // ���� index
//	return q->data[front];
//}
//void queue_print(QueueType* q) {
//	printf("Queue(front=%d rear=%d) = ", q->front, q->rear);
//	if (!is_empty(q)) {
//		int i = q->front;
//		int j = (q->rear + 1) % MAX_QUEUE_SIZE;
//		do {
//			printf("%d | ", q->data[i]);
//			i = (i + 1) % MAX_QUEUE_SIZE;
//			if (i == j)break;
//		} while (i != q->front);
//	}
//	printf("\n");
//}
//int main() {
//	QueueType q;
//	init_queue(&q);
//
//	enqueue(&q, 1);	queue_print(&q);
//	enqueue(&q, 2);	queue_print(&q);
//
//	dequeue(&q);	queue_print(&q);
//
//	enqueue(&q, 3);	queue_print(&q);
//	enqueue(&q, 4);	queue_print(&q);
//
//	dequeue(&q);	queue_print(&q);
//
//	enqueue(&q, 5);	queue_print(&q);
//	enqueue(&q, 6);	queue_print(&q);
//	return 0;
//}
/*
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	int front = q->front - 1 < 0 ? MAX_QUEUE_SIZE - 1 : (q->front -1)  % MAX_QUEUE_SIZE;
	return (q ->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�");
	}
	q->data[q->rear] = item; // index 0������ ����
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;// rear�� ��ĭ �ڸ� ����Ų��
}
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�");
	}
	int front = q->front;	// ���� ��ġ�� ���� front����
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;	// front�� ����
	return q->data[front];
}
element peek(QueueType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�");
	}
	return q->data[(q->front) % MAX_QUEUE_SIZE];
}
void queue_print(QueueType* q) {
	printf("Queue(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			printf("%d | ", q->data[i]);
			i = (i + 1) % MAX_QUEUE_SIZE;
			if (i == q->rear)break;
		} while (i != q->front);
	}
	printf("\n");
}
int main() {
	QueueType q;
	init_queue(&q);

	enqueue(&q, 1);
	queue_print(&q);
	enqueue(&q, 2);
	queue_print(&q);

	dequeue(&q);
	queue_print(&q);

	enqueue(&q, 3);
	queue_print(&q);
	enqueue(&q, 4);
	queue_print(&q);

	dequeue(&q);
	queue_print(&q);

	enqueue(&q, 5);
	queue_print(&q);
	enqueue(&q, 6);
	queue_print(&q);

	return 0;
}
*/