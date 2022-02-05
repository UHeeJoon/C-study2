#include<iostream>
#include<vector>
using namespace std;
#define MAX 100000 + 1
int n, parent[MAX];
bool visited[MAX];
vector<int> tree[MAX];
void findParent(int nodeNum) {
	visited[nodeNum] = true;
	for (int i = 0; i < (int)tree[nodeNum].size(); i++) {
		int next = tree[nodeNum][i];
		if (!visited[next]) {
			parent[next] = nodeNum;
			findParent(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	findParent(1);
	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";
	return 0;
}