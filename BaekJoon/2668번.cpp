#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, ret, cnt, num[102];
bool visited[102];
vector<int> v[102];
void dfs(int y) {
	if (visited[y]) return;
	visited[y] = 1;
	for (int i = 0; i < (int)v[y].size(); i++) {
		int ny = v[y][i];	
		if (ny == ret) {
			cnt++;
			num[ret] = 1;
		}
		dfs(ny);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		int temp; cin >> temp;
		v[i].push_back(temp);
	}
	for (int i = 1; i < n + 1; i++) {
		memset(visited, 0, sizeof(visited));
		ret = i;
		dfs(i); 
	}
	cout << cnt << "\n";
	for (int i = 1; i < 101; i++)
		if (num[i]!=0) 
			cout << i << "\n";
	return 0;
}