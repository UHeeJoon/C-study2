#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	int ans = 0;
	cin >> N >> K;

	vector<int> a(N);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int temp;
	vector<bool> vi(N);
	temp = a[0];
	while (vi[temp] != true) {
		ans++;
		vi[temp] = true;
		if (temp == K) {
			cout << ans << '\n';
			return 0;
		}
		temp = a[temp];

	}
	cout << "-1" << '\n';
	return 0;
}