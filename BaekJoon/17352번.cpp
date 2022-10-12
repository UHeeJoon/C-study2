#include<bits/stdc++.h>
using namespace std;
#define MAX 300'000 + 10
int n;
int bridge[MAX];
int getParent(int x) {
	if (bridge[x] == x) return x;
	else return getParent(bridge[x]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) bridge[a] = b;
	else bridge[b] = a;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		bridge[i] = i;
	for (int i = 0; i < n - 2; i++) {
		int start, end; cin >> start >> end;
		unionParent(start, end);
	}
	int tmp = getParent(1);
	for (int i = 2; i <= n; i++) {
		if (tmp != getParent(i)) {
			cout << tmp << ' ' << getParent(i) << '\n';
			break;
		}
	}
	return 0;
}