
#include <iostream> 
#include <queue>
using namespace std; 
#define MAX 101 
int n, m, cnt, arr[MAX][MAX]; 
bool visited[MAX]; 
queue<int> q; 
void bfs(int v) { 
	q.push(v); 
	visited[v]=true; 
	while(!q.empty()) { 
		v = q.front(); q.pop(); 
		for (auto i = 1; i <= n; i++) {
			if(arr[v][i]==1 && visited[i]==0) { 
				q.push(i); 
				visited[i]=true; 
				cnt++; 
			} 
		} 
	} 
} 
int main() { 
	cin >> n >> m; 
	for(auto i=0;i<m;i++) { 
		int x, y; cin >> x >> y;
		arr[x][y] = 1; arr[y][x] = 1;
	} 
	bfs(1); 
	cout << cnt << "\n"; 
}

/*
#include<iostream>
#include<vector>
using namespace std;
vector<int> virus[101];
bool visited[101];
int cnt, n, m;
void dfs(int y) {
	visited[y] = true;
	for (int i = 0; i < (int)virus[y].size(); i++) {
		int x = virus[y][i];
		if (!visited[x]) {
			dfs(x);
			cnt++;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int f, s; cin >> f >> s;
		virus[f].push_back(s);
		virus[s].push_back(f);
	}
	dfs(1);
	cout << cnt << "\n";
}
*/