#include<bits/stdc++.h>
using namespace std;
int n;
int W[12][12];
bool visited[12];
int ans = 987654321;
void backTracking(int cur, int idx, int sum, int cnt) {
	if (ans <= sum)return;
	if (cnt >= n) {
		if (W[idx][cur])
			ans = min(ans, sum + W[idx][cur]);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!W[idx][i])continue;
		if (ans <= sum + W[idx][i])continue;
		if (!visited[i]) {
			visited[i] = true;
			backTracking(cur, i, sum + W[idx][i], cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> W[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = true;
		backTracking(i, i, 0, 1);
		visited[i] = false;
	}
	cout << ans << '\n';
	return 0;
}

/*
#include <iostream>
using namespace std;

#define MAXN 10
int N;
int D[MAXN+1][MAXN+1];
int visited[MAXN+1];
int ans = (1<<30);
void InputData() {
	cin >> N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> D[i][j];
		}
	}
}
void dfs(int start, int cnt, int cost) {
	if (ans <= cost) return;
	if (cnt >= N) {
		// update ans
		if (D[start][0] > 0 && (ans > cost + D[start][0])) {
			ans = cost + D[start][0];
		}
		return;
	}

	for(int i=1; i<N; i++) {
		if (D[start][i] == 0) continue; //
		if (visited[i] == 1) continue;
		if (ans < cost + D[start][i]) continue; //
		visited[i] = 1;
		dfs(i, cnt+1, cost + D[start][i]);
		visited[i] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int ans = -1;
	InputData();//입력

	//여기서부터 작성
	dfs(0,1,0);
	cout << ans << "\n";//출력
	return 0;
}
*/