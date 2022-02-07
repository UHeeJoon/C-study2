#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAX 2001
int n, m, cnt;
bool check[MAX];
vector<int> friends[MAX];
void dfs(int y, int ret) {
	check[y] = 1;
	if (ret == 4) { 
		cnt = 1;
		return; 
	}
	for (int i = 0; i < (int)friends[y].size(); i++) {
		int ny = friends[y][i];
		if (check[ny]) continue;
		dfs(ny, ret + 1);
		check[ny] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		dfs(i, 0);
		if (cnt) break;
	}
	cout << cnt << "\n";
	return 0;
}