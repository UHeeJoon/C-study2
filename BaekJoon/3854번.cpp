#include<bits/stdc++.h>
using namespace std;
vector<int> tree[10010];
void dfs(vector<int>& edge, int node) {
	for (int a : tree[node]) {
		edge.push_back(a);
		dfs(edge, a);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a, b;
		for (int i = 0; i < n - 1; i++) {
			int s, e; cin >> s >> e;
			tree[e].push_back(s);
		}
		cin >> a >> b;
		vector<int> a1, b1;
		a1.push_back(a);
		b1.push_back(b);
		dfs(a1, a);
		dfs(b1, b);
		int node = 0;
		for (int a2 : a1) {
			bool flag = false;
			for (int b2 : b1) {
				if (a2 == b2) {
					flag = true;
					node = a2;
					break;
				}
			}
			if (flag)break;
		}
		cout << node << '\n';
		for (int i = 0; i < 10010; i++) {
			tree[i].clear();
		}
	}
	return 0;
}


/*
#include<iostream>
#include <cstdio>
#include <vector>
#include<cmath>
#include <memory.h> 
#define swap(a, b) { int t  = a; a  = b; b  = t; }
#define MAX_NODE 100001 
using namespace std;
// depth :: 노드의 깊이(레벨)
// ac[x][y] :: x의 2^y번째 조상을 의미
int depth[MAX_NODE];
int ac[MAX_NODE][20];
int parent[MAX_NODE];
typedef pair<int, int> pii;
vector<int> graph[MAX_NODE];
int max_level; void make_tree(int here, int parent) {
	// here의 깊이는 부모노드깊이 + 1    
	depth[here] = depth[parent] + 1;
	// here의 1번째 조상은 부모노드    
	ac[here][0] = parent;
	// MAX_NODE에 log2를 씌어 내림을 해준다.    
	max_level = (int)floor(log2(MAX_NODE));
	for (int i = 1; i <= max_level; i++) {
		// tmp :: here의 2^(i-1)번째 조상        
		
//		즉, ac[here][i] = ac[tmp][i-1]은
//		 here의 2^i번째 조상은 tmp의 2^(i-1)번째 조상의 2^(i-1)번째 조상과 같다는 의미
//		 예를들어 i = 3일때
//		 here의 8번째 조상은 tmp(here의 4번째 조상)의 4번째 조상과 같다.
//		 i =  4일때 here의 16번째 조상은 here의 8번째 조상(tmp)의 8번째와 같다.
		 
		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}
	// dfs 알고리즘    
	int len = graph[here].size();
	for (int i = 0; i < len; i++) {
		int there = graph[here][i];
		if (there != parent)
			make_tree(there, here);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc, n;
	scanf("%d", &tc);
	while (tc--) {
		memset(depth, 0, sizeof(depth));
		memset(ac, 0, sizeof(ac));
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < MAX_NODE; i++)
			graph[i].clear();
		scanf("%d", &n);
		// 양방향 그래프 형성        
		for (int i = 1; i < n; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			graph[from].push_back(to);
			graph[to].push_back(from);
			parent[to] = from;
		}
		// make_tree에 1,0이 들어가기때문에 0은 -1로 지정        
		int root;
		for (int i = 1; i <= n; i++)
			if (parent[i] == 0) {
				root = i;
				break;
			}
		depth[0] = -1;
		// 루트 노드인 1번 노드부터 트리 형성        
		make_tree(root, 0);
		int a, b;
		scanf("%d %d", &a, &b);
		if (depth[a] != depth[b]) {
			// depth[b] >= depth[a]가 되도록 swap           
			if (depth[a] > depth[b])
				swap(a, b);
			// b를 올려서 depth를 맞춰준다.            
			for (int i = max_level; i >= 0; i--) {
				// b의 2^i번째 조상이 a의 depth보다 크거나 같으면 계속 조상을 타고간다.                
				if (depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
			}
		}
		int lca = a;
		// a와 b가 다르다면 현재 깊이가 같으니      
		// 깊이를 계속 올려 조상이 같아질 때까지 반복한다.       
		if (a != b) {
			for (int i = max_level; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		printf("%d\n", lca);
	}
	return 0;
}
*/

/*
#include<iostream>
#include<algorithm>
using namespace std;

int parent[10001];
bool visit[10001];
int T, N, A, B, u, v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N;

		// 초기화
		for (int i = 1; i <= N; i++)
		{
			visit[i] = false;
			parent[i] = i;
		}

		// 간선정보 입력
		for (int i = 0; i < N - 1; i++)
		{
			cin >> A >> B;
			parent[B] = A;
		}

		// LCA 찾기
		cin >> u >> v;
		visit[u] = true;

		while (u != parent[u])
		{
			u = parent[u];
			visit[u] = true;
		}
		while (true)
		{
			if (visit[v])
			{
				cout << v << '\n';
				break;
			}
			v = parent[v];
		}

	}
}
*/