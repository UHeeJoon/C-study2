#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b; cin >> a >> b;
	int result = 987654321;
	queue<pair <long long, int>> q; q.push({ a, 1 });
	while (!q.empty()) {
		long long tmp = q.front().first;
		a = q.front().second; q.pop();
		for (long long ret : {tmp * 2, tmp * 10 + 1}) {
			if (ret == b) {
				result = min(a, result);
			}
			else if (ret > b)continue;
			else
				q.push({ ret, a + 1 });
		}
	}
	cout << (result == 987654321 ? -1 : result + 1) << '\n';
	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int mini = 10000; // 임의의 큰수
long long A, B, cnt;

void dfs(long long a, int cnt)
{
	if (a > B) return;

	if (a == B)
	{
		mini = min(mini, cnt);
	}
	dfs(a * 2, cnt + 1);
	dfs(a * 10 + 1, cnt + 1);

}

int main()
{
	cin >> A >> B;

	dfs(A, 1);

	if (mini == 10000) cout << -1;
	else cout << mini;
}

//  다른 방법

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int a, b;

int main() {
	cin >> a >> b;

	int cnt = 0;
	while (1) {
		if (a > b) {
			cout << -1 << '\n';
			break;
		}
		if (a == b) {
			cout << cnt + 1 << '\n';
			break;
		}

		if (b % 10 == 1) {
			b /= 10;
		}
		else if(b % 2 == 0){
			b /= 2;
		}
		else {
			cout << -1 << '\n';
			break;
		}
		cnt++;
	}
	return 0;
}
*/