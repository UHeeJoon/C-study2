#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 5005

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
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element peek(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	QueueType* q = (QueueType*)malloc(sizeof(QueueType));
	init_queue(q);

	for (int i = 0; i < n; i++) {
		enqueue(q, i + 1);
	}
	printf("<");
	int idx = 0;
	while (idx < n) {
		for (int i = 1; i <= k; i++) {
			if (i == k) {
				++idx;
				if (idx == n) {
					printf("%d", peek(q));
					dequeue(q);
				}
				else {
					printf("%d, ", peek(q));
					dequeue(q);
				}
			}
			else {
				enqueue(q, peek(q));
				dequeue(q);
			}
		}
	}
	printf(">");
	free(q);
	return 0;
}