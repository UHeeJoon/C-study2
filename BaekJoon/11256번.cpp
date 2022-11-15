#include<bits/stdc++.h>
using namespace std;
int box[1010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc;  cin >> tc;
	while (tc--) {
		int j, n; cin >> j >> n;
		for (int i = 0; i < n; i++) {
			int width, height; cin >> width >> height;
			box[i] = width * height;
		}
		sort(box, box + n, greater<>());
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			j -= box[i];
			cnt++;
			if (j <= 0)break;
		}
		cout << cnt << '\n';
	}
	return 0;
}