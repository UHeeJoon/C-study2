#include<iostream>
#include<queue>
using namespace std;
int n, k, answer;
bool visited[100010];
void bfs(int tmp) {
    queue<pair<int, int>> q;
    q.emplace(n, 0);

    while (!q.empty()) {
        int locate = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (locate == k) {
            answer = cost;
            break;
        }

        int x_1 = locate - 1;
        int x_2 = locate + 1;
        int x_3 = locate * 2;


        if (0 <= x_1 && !visited[x_1]) {
            visited[x_1] = true;
            q.emplace(x_1, cost + 1);
        }

        if (x_2 <= k && !visited[x_2]) {
            visited[x_2] = true;
            q.emplace(x_2, cost + 1);
        }

        if (x_3 <= k + 1 && !visited[x_3]) {
            visited[x_3] = true;
            q.emplace(x_3, cost + 1);
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	bfs(n);
	return 0;
}