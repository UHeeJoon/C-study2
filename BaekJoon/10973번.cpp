#include<bits/stdc++.h>
using namespace std;
#define MAX 10010
#define INF 2147483647
int permu[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> permu[i];
	}

	if (prev_permutation(permu, permu + n))
		for (int i = 0; i < n; i++)
			cout << permu[i] << ' ';
	else
		cout << -1;
	cout << '\n';
	return 0;
}