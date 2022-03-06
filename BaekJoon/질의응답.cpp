#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
int o, w, num, cnt = 1;
char c;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		bool check = false;
		cin >> o >> w;
		if (o == 0 && w == 0) break;
		while (1) {
			cin >> c >> num;
			if (c == '#' && num == 0) break;
			if (c == 'E') w -= num;
			else w += num;
			if (w <= 0) check = true;
		}
		if (check) {
			cout << cnt << " RIP\n";
		}
		else {
			if (o / 2 < w && w < 2 * o)
				cout << cnt << " :-)\n";
			else
				cout << cnt << " :-(\n";
		}
		cnt++;
	}
    return 0;
}