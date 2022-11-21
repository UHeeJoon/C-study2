#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100'000
typedef struct _heap {
	int data[MAX_SIZE];
	int heap_size;
}heap;
heap* init(heap* h) {
	h = (heap*)malloc(sizeof(heap));
	h->heap_size = 0;
	return h;
}
void swap(int* a, int* b, int* c) {
	*a = *b;
	*b = *c;
	*c = *a;
}
void add(heap* h, int data) {
	h->heap_size += 1;
	h->data[h->heap_size] = data;
	int me = h->heap_size;
	int parent = me / 2;
	while (parent) {
		if (h->data[parent] < h->data[me]) {
			int temp = h->data[parent];
			swap(&temp, &h->data[parent], &h->data[me]);
			me = parent;
			parent = me / 2;
		}
		else {
			break;
		}
	}
	return;
}
int _remove(heap* h) {
	int res = h->data[1];
	h->data[1] = h->data[h->heap_size];
	h->heap_size -= 1;
	int me = 1;
	int child = 2;
	while (child <= h->heap_size) {
		if (child + 1 <= h->heap_size && h->data[child] < h->data[child + 1]) {
			child += 1;
		}
		if (h->data[me] < h->data[child]) {
			int temp = h->data[me];
			swap(&temp, &h->data[me], &h->data[child]);
			me = child;
			child = me * 2;
		}
		else {
			break;
		}
	}
	return res;
}
void printHip(heap *p, int idx) {
	if (p->heap_size < idx ) {
		return;
	}
	printf("(%d ", p->data[idx]);
	printHip(p, idx * 2);
	if (p->heap_size < idx + 1 || idx == 1) {
		printf(")");
		return;
	}
	printf("%d)", p->data[idx + 1]);
	return;
}
int main() {
	heap* h = NULL;
	h = init(h);
	while (1) {
		char str[20];
		printf(">명령어를 입력하시오(중지를 원하면 stop을 입력): insert/delete\n");
		scanf("%s", str);
		if (strcmp(str,"stop") == 0)break;
		else if (strcmp(str, "insert") == 0) {
			int num;
			printf("> 숫자를 입력하시오.\n");
			scanf("%d", &num);
			add(h, num);
			printHip(h, 1);
			printf("\n");
		}
		else if (strcmp(str, "delete") == 0) {
			_remove(h);
			printHip(h, 1);
			printf("\n");
		}
		else {
			printf("입력오류 다시 입력해주세요\n");
		}
	}
	printHip(h, 1);
	return 0;
}



//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX_VERTICES 50
//typedef struct {
//    int n;
//    char subject[50];
//} element;
//typedef struct GraphNode {
//    element vertex;
//    struct GraphNode* link;
//}GraphNode;
//typedef struct GraphType {
//    int n;
//    GraphNode* adj_list[MAX_VERTICES];
//}GraphType;
//void graph_init(GraphType* g) {
//    g->n = 0;
//    for (int v = 0; v < MAX_VERTICES; v++) {
//        g->adj_list[v] = NULL;
//    }
//}
//void insert_vertex(GraphType* g, int v) {
//    if (((g->n) + 1) > MAX_VERTICES) {
//        fprintf(stderr, "정점개수 초과");
//        return;
//    }
//    g->n++;
//}
//void insert_edge(GraphType* g, element u, element v) {
//    GraphNode* node;
//    if (u.n >= g->n || v.n >= g->n) {
//        fprintf(stderr, "정점 번호 오류");
//        return;
//    }
//    node = (GraphNode*)malloc(sizeof(GraphNode));
//    node->vertex = v;
//    node->link = g->adj_list[u.n];
//    g->adj_list[u.n] = node;
//}
//
//
//void dfs(GraphType* g, int* tmp, int idx, element* data) {
//    printf("%s => ", data[idx].subject);
//    GraphNode* node = g->adj_list[idx];
//    while (node != NULL) {
//        int u = node->vertex.n;
//        tmp[u]--;
//        if (tmp[u] == 0) {
//            dfs(g, tmp, u, data);
//        }
//        node = node->link;
//    }
//}
//
//int topo_sort(GraphType* g, element* data) {
//    int i;
//
//    int* in_degree = (int*)malloc(g->n * sizeof(int));
//    for (int i = 0; i < g->n; i++) {
//        in_degree[i] = 0;
//    }
//    for (i = 0; i < g->n; i++) {
//        GraphNode* node = g->adj_list[i];
//        while (node != NULL) {
//            in_degree[node->vertex.n]++;
//            node = node->link;
//        }
//    }
//
//    int* root = (int*)malloc(g->n * sizeof(int));
//    int idx = 0;
//
//    for (i = 0; i < g->n; i++) {
//        if (in_degree[i] == 0) {
//            root[idx++] = i;
//        }
//    }
//    for (int i = 0; i < idx; i++) {
//        dfs(g, in_degree, root[i], data);
//    }
//    printf("\n");
//    free(in_degree);
//    return i == g->n;
//}
//
//
//element find(char a[], int n, element* data) {
//    for (int i = 0; i < n; i++) {
//        if (strcmp(data[i].subject, a) == 0)
//            return data[i];
//    }
//}
//
//int main() {
//    GraphType g;
//    printf("입력할 과목 수를 입력하세요. >> ");
//    int n; (void)scanf("%d", &n);
//    (void)getchar();
//    graph_init(&g);
//    element* data = (element*)malloc(n * sizeof(element));
//    for (int i = 0; i < n; i++) {
//        element tmp;
//        printf("과목을 입력하세요. >> ");
//        fgets(tmp.subject, 50, stdin);
//        tmp.n = i;
//        tmp.subject[strlen(tmp.subject) - 1] = '\0';
//        data[i] = tmp;
//        insert_vertex(&g, i);
//    }
//    printf("\n");
//    while (1) {
//        char subject[50] = { 0, }, pre_subject[50] = { 0, };
//        printf("과목을 입력하세요.(끝낼려면 \"끝\" 입력) >> ");
//        fgets(subject, 50, stdin);
//        subject[strlen(subject) - 1] = '\0';
//        if (strcmp(subject, "끝") == 0)break;
//        printf("선수 과목을 입력하세요. >> ");
//        fgets(pre_subject, 50, stdin);
//        pre_subject[strlen(pre_subject) - 1] = '\0';
//        insert_edge(&g, find(pre_subject, n, data), find(subject, n, data));
//    }
//    topo_sort(&g, data);
//    free(data);
//    return 0;
//}

/*
8
C언어
C++
JAVA
자료구조
알고리즘
인터넷 프로그래밍
미적분학
공업수학
C++
C언어
JAVA
C언어
자료구조
C++
JAVA
C++
인터넷 프로그래밍
JAVA
알고리즘
자료구조
공업수학
미적분학
끝
*/


/*insert_edge(&g, data[0], data[1]);
insert_edge(&g, data[0], data[2]);
insert_edge(&g, data[1], data[3]);
insert_edge(&g, data[1], data[2]);
insert_edge(&g, data[2], data[5]);
insert_edge(&g, data[3], data[4]);
insert_edge(&g, data[6], data[7]);*/



//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct {
//	char name[100];
//}element;
//typedef struct ListNode{
//	element data; struct ListNode* link;
//} ListNode;
//void error(char* message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//ListNode* insert_first(ListNode* head, element values) {
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	p->data = values;
//	p->link = head;
//	head = p;
//	return head;
//}
//
//void print_list(ListNode* head) {
//	if (head == NULL) return; 
//	print_list(head->link);
//	printf("%s\n", head->data.name);
//}
//void print_list_reverse(ListNode* head) {
//	for (ListNode* p = head; p != NULL; p = p->link) {
//		printf("%s\n", p->data.name);
//	}
//	printf("\n");
//}
//int main() {
//	ListNode* head = NULL;
//	element input;
//	printf("이번학기 수강과목을 입력하세요! (모두 입력후에는 \"끝\"을 입력하세요)\n");
//	while (1) {
//		fgets(input.name, sizeof(input.name), stdin);
//		input.name[(int)strlen(input.name) - 1] = '\0';
//		if (!strcmp(input.name, "끝")) {
//			break;
//		}
//		head = insert_first(head, input);
//	}
//	printf("\n");
//	printf("입력된 순서 : \n");
//	print_list(head);
//	printf("\n");
//	printf("입력된 순서의 역순으로 출력 : \n");
//	print_list_reverse(head);
//
//	return 0;
//}

//#pragma warning(disable : 4996)
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX_VERTICES 50
//typedef struct {
//    int n;
//    char subject[50];
//} element;
//typedef struct GraphNode {
//    element vertex;
//    struct GraphNode* link;
//}GraphNode;
//typedef struct GraphType {
//    int n;
//    GraphNode* adj_list[MAX_VERTICES];
//}GraphType;
//void graph_init(GraphType* g) {
//    g->n = 0;
//    for (int v = 0; v < MAX_VERTICES; v++) {
//        g->adj_list[v] = NULL;
//    }
//}
//void insert_vertex(GraphType* g, int v) {
//    if (((g->n) + 1) > MAX_VERTICES) {
//        fprintf(stderr, "정점개수 초과");
//        return;
//    }
//    g->n++;
//}
//void insert_edge(GraphType* g, element u, element v) {
//    GraphNode* node;
//    if (u.n >= g->n || v.n >= g->n) {
//        fprintf(stderr, "정점 번호 오류");
//        return;
//    }
//    node = (GraphNode*)malloc(sizeof(GraphNode));
//    node->vertex = v;
//    node->link = g->adj_list[u.n];
//    g->adj_list[u.n] = node;
//}
//
//#define MAX_QUEUE_SIZE 50
//
//typedef struct {
//    element data[MAX_QUEUE_SIZE];
//    int front, rear;
//}QueueType;
//void error(char* message) {
//    fprintf(stderr, "%s\n", message);
//    exit(1);
//}
//void init_queue(QueueType* q) {
//    q->front = q->rear = 0;
//}
//int is_empty(QueueType* q) {
//    int front = q->front - 1 < 0 ? MAX_QUEUE_SIZE - 1 : (q->front - 1) % MAX_QUEUE_SIZE;
//    return (q->front == q->rear);
//}
//int is_full(QueueType* q) {
//    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//void enqueue(QueueType* q, element item) {
//    if (is_full(q)) {
//        error("큐가 포화상태입니다");
//    }
//    q->data[q->rear] = item; // index 0번부터 삽입
//    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;// rear를 한칸 뒤를 가르킨다
//}
//element dequeue(QueueType* q) {
//    if (is_empty(q)) {
//        error("큐가 공백상태입니다");
//    }
//    int front = q->front;   // 현재 위치를 담을 front변수
//    q->front = (q->front + 1) % MAX_QUEUE_SIZE;   // front값 증가
//    return q->data[front];
//}
//
//
//int topo_sort(GraphType* g, element* data) {
//    int i;
//    QueueType q;
//    GraphNode* node;
//
//    int* in_degree = (int*)malloc(g->n * sizeof(int));
//    for (int i = 0; i < g->n; i++) {
//        in_degree[i] = 0;
//    }
//    for (i = 0; i < g->n; i++) {
//        GraphNode* node = g->adj_list[i];
//        while (node != NULL) {
//			//printf("%d %s", node->vertex.n, node->vertex.subject);
//            in_degree[node->vertex.n]++;
//            node = node->link;
//        }
//        //printf("\n");
//    }
//    init_queue(&q);
//    for (i = 0; i < g->n; i++) {
//        if (in_degree[i] == 0) {
//            enqueue(&q, data[i]);
//        }
//    }
//    while (!is_empty(&q)) {
//        element w;
//        w = dequeue(&q);
//        printf("%s => ", w.subject);
//        node = g->adj_list[w.n];
//        while (node != NULL) {
//            int u = node->vertex.n;
//            in_degree[u]--;
//            if (in_degree[u] == 0) enqueue(&q, data[u]);
//            node = node->link;
//        }
//    }
//    free(in_degree);
//    printf("\n");
//    return i == g->n;
//}
//
//
//int main() {
//    GraphType g;
//    printf("입력할 과목 수를 입력하세요. >> ");
//    int n; (void)scanf("%d", &n);
//    (void)getchar();
//
//    element* data = (element*)malloc(n * sizeof(element));
//    for (int i = 0; i < n; i++) {
//        element tmp;
//        printf("과목을 입력하세요. >> ");
//        fgets(tmp.subject, 50, stdin);
//        tmp.n = i;
//        tmp.subject[strlen(tmp.subject) - 1] = '\0';
//        data[i] = tmp;
//    }
//    /*
//		
//C언어
//C++
//JAVA
//자료구조
//알고리즘
//인터넷 프로그래밍
//미적분학
//공업수학
//
//	};*/
//   
//    graph_init(&g);
//    insert_vertex(&g, 0);
//    insert_vertex(&g, 1);
//    insert_vertex(&g, 2);
//    insert_vertex(&g, 3);
//    insert_vertex(&g, 4);
//    insert_vertex(&g, 5);
//    insert_vertex(&g, 6);
//    insert_vertex(&g, 7);
//	insert_edge(&g, data[0], data[1]);
//	insert_edge(&g, data[0], data[2]);
//	insert_edge(&g, data[1], data[3]);
//	insert_edge(&g, data[1], data[2]);
//	insert_edge(&g, data[2], data[5]);
//	insert_edge(&g, data[3], data[4]);
//	insert_edge(&g, data[6], data[7]);
//
//    topo_sort(&g, data);
//    free(data);
//    return 0;
//}








