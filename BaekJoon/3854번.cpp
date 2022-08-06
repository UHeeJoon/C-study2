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
// depth :: ����� ����(����)
// ac[x][y] :: x�� 2^y��° ������ �ǹ�
int depth[MAX_NODE];
int ac[MAX_NODE][20];
int parent[MAX_NODE];
typedef pair<int, int> pii;
vector<int> graph[MAX_NODE];
int max_level; void make_tree(int here, int parent) {
	// here�� ���̴� �θ������ + 1    
	depth[here] = depth[parent] + 1;
	// here�� 1��° ������ �θ���    
	ac[here][0] = parent;
	// MAX_NODE�� log2�� ���� ������ ���ش�.    
	max_level = (int)floor(log2(MAX_NODE));
	for (int i = 1; i <= max_level; i++) {
		// tmp :: here�� 2^(i-1)��° ����        
		
//		��, ac[here][i] = ac[tmp][i-1]��
//		 here�� 2^i��° ������ tmp�� 2^(i-1)��° ������ 2^(i-1)��° ����� ���ٴ� �ǹ�
//		 ������� i = 3�϶�
//		 here�� 8��° ������ tmp(here�� 4��° ����)�� 4��° ����� ����.
//		 i =  4�϶� here�� 16��° ������ here�� 8��° ����(tmp)�� 8��°�� ����.
		 
		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}
	// dfs �˰���    
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
		// ����� �׷��� ����        
		for (int i = 1; i < n; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			graph[from].push_back(to);
			graph[to].push_back(from);
			parent[to] = from;
		}
		// make_tree�� 1,0�� ���⶧���� 0�� -1�� ����        
		int root;
		for (int i = 1; i <= n; i++)
			if (parent[i] == 0) {
				root = i;
				break;
			}
		depth[0] = -1;
		// ��Ʈ ����� 1�� ������ Ʈ�� ����        
		make_tree(root, 0);
		int a, b;
		scanf("%d %d", &a, &b);
		if (depth[a] != depth[b]) {
			// depth[b] >= depth[a]�� �ǵ��� swap           
			if (depth[a] > depth[b])
				swap(a, b);
			// b�� �÷��� depth�� �����ش�.            
			for (int i = max_level; i >= 0; i--) {
				// b�� 2^i��° ������ a�� depth���� ũ�ų� ������ ��� ������ Ÿ����.                
				if (depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
			}
		}
		int lca = a;
		// a�� b�� �ٸ��ٸ� ���� ���̰� ������      
		// ���̸� ��� �÷� ������ ������ ������ �ݺ��Ѵ�.       
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

		// �ʱ�ȭ
		for (int i = 1; i <= N; i++)
		{
			visit[i] = false;
			parent[i] = i;
		}

		// �������� �Է�
		for (int i = 0; i < N - 1; i++)
		{
			cin >> A >> B;
			parent[B] = A;
		}

		// LCA ã��
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