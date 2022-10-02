#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
#define MAX 20010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
#define RED 1
#define BLUE 2
vector<int> vect[MAX];
int visited[MAX];
int V, E;
void BFS(int start){
	visited[start] = RED;
	queue<int> q;
	q.push(start);
	while (q.size() != 0){
		int now = q.front();
		q.pop();
		for (int i = 0; i < vect[now].size(); i++){
			if (visited[vect[now][i]] == 0){
				q.push(vect[now][i]);
				if (visited[now] == RED) visited[vect[now][i]] = BLUE;
				else if (visited[now] == BLUE) visited[vect[now][i]] = RED;
			}
		}

	}

}
bool check(){
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
		for (int i = 0; i < E; i++){
			cin >> u >> v;
			vect[u].push_back(v);
			vect[v].push_back(u);
		}
		for (int i = 1; i <= V; i++){
			if (visited[i] == 0){
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