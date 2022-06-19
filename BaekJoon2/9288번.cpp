#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		bool visited[13] = { 0, };
		int tmp; cin >> tmp;
		cout << "Case " << i << ":\n";
		for (int j = 1; j <= 6; j++) {
			if (visited[j] || tmp - j < 1 || tmp - j > 6) continue;
			visited[j] = true;
			visited[tmp - j] = true;
			cout << "(" << j << "," << tmp - j << ")\n";
		}
	}
	return 0;
}