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
// path[index] : index 정점을 갈 때 경유하는 정점
int path[20'001];
// parent[index] : index 정점의 루트 노드
int parent[20'001];
// 반환 값 : u가 속한 집합의 루트 노드
int Find(int u){
    while (u != parent[u])
        u = parent[u] = parent[parent[u]]; // 경로 단축
    return u;
}
// 반환 값 : u와 v를 합친 뒤에 루트 노드
int Union(int u, int v){
    if (u == -1 || v == -1)
        return max(u, v);
    // 각 집합의 루트 노드를 찾는다.
    u = Find(u);
    v = Find(v);
    // 같은 집합인 경우
    if (u == v)
        return u;
    // 합친다.
    parent[u] = v;
    return v;
}
bool IsBipartiteGraph(int u, int v){
    // 각 정점의 루트 노드를 찾는다.
    u = Find(u);
    v = Find(v);
    // 이미 같은 집합에 있다면 이 간선이 추가될 때 사이클이 생긴다.
    if (u == v)
        return false;
    // 간선을 추가하고, 집합을 나눈다.
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
        // 초기화
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
            // 이 간선이 추가될 때 사이클이 생기는지 확인한다.
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