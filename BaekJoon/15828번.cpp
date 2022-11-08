#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	queue<int> q;
	while (1) {
		int num; cin >> num;
		if (num == -1)break;
		else if (!num) {
			q.pop();
			continue;
		}
		if (q.size() >= n)continue;
		q.push(num);
	}
	if (q.empty()) {
		cout << "empty\n";
	}
	else {
		while (!q.empty()) {
			cout << q.front() << ' ';
			q.pop();
		}
	}
	cout << '\n';
	return 0;
}