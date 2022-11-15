#include<bits/stdc++.h>
using namespace std;
pair<int, int>score[110];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l, k; cin >> n >> l >> k;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> score[i].second >> score[i].first;
	}
	sort(score, score + n, [](pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
		});
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (score[i].first <= l) {
			sum += 140;
			k--;
		}
		else if (score[i].first > l && score[i].second <= l) {
			cnt++;
		}
		if (k <= 0)break;
	}
	cout << sum + min(k, cnt) * 100 << '\n';
	return 0;
}