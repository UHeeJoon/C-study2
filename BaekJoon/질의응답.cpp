#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 20010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int n;
int W[12][12];
int dist[12][12];
bool visited[12];
void backTracking(int cur,int idx, int sum, int cnt) {
	if (cnt == n) {
		if(W[idx][cur])
			dist[cur][cur] = min(dist[cur][cur], sum + W[idx][cur]);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (!W[idx][i])continue;
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
	fill(&dist[0][0], &dist[0][0] + 12 * 12, 987654321);
	for (int i = 1; i <= n; i++) {
		visited[i] = true;
		backTracking(i, i, 0, 1);
		visited[i] = false;
	}
	int ans = 987654321;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, dist[i][i]);
	}
	cout << ans << '\n';
	return 0;
}