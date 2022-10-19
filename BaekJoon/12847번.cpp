#include<bits/stdc++.h>
using namespace std;
#define MAX 100'000 + 10
typedef long long ll;
ll day[MAX];
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		day[i] = day[i - 1] + num;
	}
	int i = 1, j = m;
	ll sum = 0;
	while (j <= n) {
		sum = max(sum, day[j] - day[i - 1]);
		i++;
		j++;
	}
	cout << sum << '\n';
	return 0;
}