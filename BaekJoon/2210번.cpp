#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int board[6][6];
vector<string> v;
void dfs(int y, int x, int length, string num) {
	if (length == 6) {
		if (find(v.begin(), v.end(), num) == v.end())
			v.push_back(num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
		dfs(ny, nx, length+1, num + to_string(board[ny][nx]));
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) 
			dfs(i, j, 1, to_string(board[i][j]));
		
	cout << (int)v.size() << "\n";
	return 0;
}
/*
#include<iostream>
#include<set>
using namespace std;
int a[6][6];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
set<int> ans;
void dfs(int x, int y, int lenth, int num) {
    if (lenth == 6) {
        ans.insert(num);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        dfs(nx, ny, lenth + 1, num * 10 + a[nx][ny]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, 1, a[i][j]);
        }
    }
    cout << ans.size() << '\n';
}

*/