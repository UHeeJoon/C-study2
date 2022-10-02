#include<bits/stdc++.h>
using namespace std;
#define MAX 20010
#define RED 1
#define BLUE 2
vector<int> vect[MAX];
int visited[MAX];
int V, E;
void BFS(int start) {
	visited[start] = RED;
	queue<int> q;
	q.push(start);
	while (q.size() != 0) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vect[now].size(); i++) {
			if (visited[vect[now][i]] == 0) {
				q.push(vect[now][i]);
				if (visited[now] == RED) visited[vect[now][i]] = BLUE;
				else if (visited[now] == BLUE) visited[vect[now][i]] = RED;
			}
		}

	}

}
bool check() {
	for (int i = 1; i <= V; i++)
		for (int j = 0; j < vect[i].size(); j++)
			if (visited[i] == visited[vect[i][j]])
				return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc, u, v;  cin >> tc;
	while (tc--) {
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			vect[u].push_back(v);
			vect[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				BFS(i);
			}
		}
		if (check())
			cout << "YES\n";
		else
			cout << "NO\n";
		memset(visited, 0, sizeof(visited));
		memset(vect, 0, sizeof(vect));
	}
	return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;
int K, V, E;
// path[index] : index ������ �� �� �����ϴ� ����
int path[20'001];
// parent[index] : index ������ ��Ʈ ���
int parent[20'001];
// ��ȯ �� : u�� ���� ������ ��Ʈ ���
int Find(int u){
    while (u != parent[u])
        u = parent[u] = parent[parent[u]]; // ��� ����
    return u;
}
// ��ȯ �� : u�� v�� ��ģ �ڿ� ��Ʈ ���
int Union(int u, int v){
    if (u == -1 || v == -1)
        return max(u, v);
    // �� ������ ��Ʈ ��带 ã�´�.
    u = Find(u);
    v = Find(v);
    // ���� ������ ���
    if (u == v)
        return u;
    // ��ģ��.
    parent[u] = v;
    return v;
}
bool IsBipartiteGraph(int u, int v){
    // �� ������ ��Ʈ ��带 ã�´�.
    u = Find(u);
    v = Find(v);
    // �̹� ���� ���տ� �ִٸ� �� ������ �߰��� �� ����Ŭ�� �����.
    if (u == v)
        return false;
    // ������ �߰��ϰ�, ������ ������.
    int x = Union(u, path[v]);
    int y = Union(v, path[u]);
    path[x] = y;
    path[y] = x;
    return true;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> K;
    while (K--){
        cin >> V;
        // �ʱ�ȭ
        for (int i = 1; i <= V; ++i){
            parent[i] = i;
            path[i] = -1;
        }
        cin >> E;
        bool isBipartiteGraph = true;
        while (E--){
            int u, v;
            cin >> u >> v;
            if (false == isBipartiteGraph)
                continue;
            // �� ������ �߰��� �� ����Ŭ�� ������� Ȯ���Ѵ�.
            if (false == IsBipartiteGraph(u, v))
                isBipartiteGraph = false;
        }
        if (isBipartiteGraph)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
*/