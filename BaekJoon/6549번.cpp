#include<bits/stdc++.h>
using namespace std;
int h[100010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int N = 0;
		long long ans = 0;
		stack<int> s;
		cin >> N;
		if (!N)break;
		for (int i = 1; i <= N; i++)
			cin >> h[i];
		s.push(0);
		for (int i = 1; i <= N + 1; i++) {
			while (!s.empty() && h[s.top()] > h[i]) {
				int check = s.top();
				s.pop();
				ans = max(ans, (long long)h[check] * (i - s.top() - 1));
			}
			s.push(i);
		}
		cout << ans << '\n';
		memset(h, 0, sizeof(h));
	}
	return 0;
}