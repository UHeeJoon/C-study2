#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> p[100001];
int n, cnt, tmp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].second >> p[i].first;
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		if (p[i].second >= tmp) {
			cnt++;
			tmp = p[i].first;
		}
	}
	cout << cnt << "\n";
}