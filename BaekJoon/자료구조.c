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
	q->front = 0, q->rear = -1;
	// rear�� -1�� �����Ͽ� index 0������ ����
}
int is_empty(QueueType* q) {
	if (q->front == -1) return 1; // -1�� �� ����
	int rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	return (q->front == rear);
}
int is_full(QueueType* q) {
	if (q->rear == -1)	return 0; // -1�� �� ����
	return ((q->rear + 2) % MAX_QUEUE_SIZE == q->front);
	// front ==1, rear ==0 �� ���� ��Ȳ ���� ���� rear + 2
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) { error("ť�� ��ȭ�����Դϴ�"); }
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // ���Ե� index
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q)) { error("ť�� ��������Դϴ�"); }
	int front = q->front;	// ���� index
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // ���� index
	return q->data[front];
}
void queue_print(QueueType* q) {
	printf("Queue(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		int j = (q->rear + 1) % MAX_QUEUE_SIZE;
		do {
			printf("%d | ", q->data[i]);
			i = (i + 1) % MAX_QUEUE_SIZE;
			if (i == j)break;
		} while (i != q->front);
	}
	printf("\n");
}
int main() {
	QueueType q;
	init_queue(&q);

	enqueue(&q, 1);	queue_print(&q);
	enqueue(&q, 2);	queue_print(&q);

	dequeue(&q);	queue_print(&q);

	enqueue(&q, 3);	queue_print(&q);
	enqueue(&q, 4);	queue_print(&q);

	dequeue(&q);	queue_print(&q);

	enqueue(&q, 5);	queue_print(&q);
	enqueue(&q, 6);	queue_print(&q);
	return 0;
}
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