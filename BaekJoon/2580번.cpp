
#include<iostream>
#include<vector>
using namespace std;
int sudo[10][10], cnt;
bool found = false;
vector<pair<int, int>> space;
bool check(pair<int, int> p, int k) {
	for (int i = 0; i < 9; i++) {
		if (sudo[i][p.second] == k && i != p.first)
			return false;
		if (sudo[p.first][i] == k && i != p.second)
			return false;
	}
	int ny = (p.first / 3) * 3, nx = (p.second / 3) * 3;
	for (int i = ny; i < ny + 3; i++) {
		for (int j = nx; j < nx + 3; j++) {
			if (sudo[i][j] == k)
				if (i != p.first && j != p.second)
					return false;
		}
	}
	return true;
}
void dfs(int N) {
	if (N == cnt) {
		found = true;
		return;
	}
	for (int i = 1; i < 10; i++) {
		sudo[space[N].first][space[N].second] = i;
		if (check(space[N], i))
			dfs(N + 1);
		if (found) return;
	}
	sudo[space[N].first][space[N].second] = 0;
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudo[i][j];
			if (!sudo[i][j]) {
				space.push_back({ i,j });
				cnt += 1;
			}
		}
	}
	dfs(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudo[i][j] << " ";
		}
		cout << "\n";
	}
}
/*
// 답만 출력
#include<iostream>
#include<vector>
using namespace std;
int sudo[10][10], cnt, sudo2[10][10];
bool found = false;
vector<pair<int, int>> space;
bool check(pair<int, int> p, int k) {
	for (int i = 0; i < 9; i++) {
		if (sudo[i][p.second] == k && i != p.first)
			return false;
		if (sudo[p.first][i] == k && i != p.second)
			return false;
	}
	int ny = (p.first / 3) * 3, nx = (p.second / 3) * 3;
	for (int i = ny; i < ny + 3; i++) {
		for (int j = nx; j < nx + 3; j++) {
			if (sudo[i][j] == k)
				if(i != p.first && j !=p.second)
					return false;
		}
	}
	return true;
}
void dfs(int N) {
	if (N == cnt) {
		found = true;
		return;
	}
	for (int i = 1; i < 10; i++) {
		sudo[space[N].first][space[N].second] = i;
		if (check(space[N],i))
			dfs(N + 1);
		if (found) return;
	}
	sudo[space[N].first][space[N].second] = 0;
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudo[i][j];
			sudo2[i][j] = sudo[i][j];
			if (!sudo[i][j]) {
				space.push_back({ i,j });
				cnt += 1;
			}
		}
	}
	dfs(0);
	cout << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudo[i][j] != sudo2[i][j])
				cout << sudo[i][j] << " ";
			else
				cout << 0 << " ";
		}
		cout << "\n";
	}
}
*/