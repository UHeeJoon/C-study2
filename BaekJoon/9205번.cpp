#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100 + 2;
vector<int> graph[MAX];
bool visited[MAX];
int distance(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void DFS(int y) {
	visited[y] = true;
	for (int i = 0; i < graph[y].size(); i++) {
		int next = graph[y][i];
		if (visited[next] == false)
			DFS(next);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		for (int i = 0; i < MAX; i++)
			graph[i].clear();
		memset(visited, false, sizeof(visited));
		cin >> n;
		vector<pair<int, int>> vp;
		for (int i = 0; i < n + 2; i++) {
			int y, x;
			cin >> y >> x;
			vp.push_back(make_pair(y, x));
		}
		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				if (distance(vp[i], vp[j]) <= 50 * 20) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		DFS(0);
		if (visited[n + 1])
			printf("happy\n");
		else
			printf("sad\n");
	}

}