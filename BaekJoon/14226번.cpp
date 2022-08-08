#include<bits/stdc++.h>
using namespace std;
bool visited[2010][2010];
struct board {
	int now;
	int copy;
	int cnt;
};
int bfs(int start, int end) {
	queue<board> q;
	q.push({ start, 0, 0 });
	visited[start][0] = 1;
	while (!q.empty()) {
		int now = q.front().now;
		int copy = q.front().copy;
		int cnt = q.front().cnt;
		q.pop();
		if (now == end) {
			return cnt;
		}
		if (now > 0 && now < 2010) {
			if (!visited[now][now]) {
				visited[now][now] = true;
				q.push({ now, now, cnt + 1 });
			}
			if (!visited[now - 1][copy]) {
				visited[now - 1][copy] = true;
				q.push({ now - 1 , copy, cnt + 1 });
			}
		}
		if (copy > 0 && now + copy < 2010) {
			if (!visited[now + copy][copy]) {
				visited[now + copy][copy] = true;
				q.push({ now + copy, copy, cnt + 1 });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int s; cin >> s;
	cout << bfs(1, s) << '\n';
	return 0;
}