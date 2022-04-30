#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int w; cin >> w;
	bool flag = false;
	for (int i = 1; i < w; i++) {
		for (int j = 1; j < w; j++) {
			if (i + j > w) break;
			else if (i + j == w && i % 2 == 0 && j % 2 == 0)
				flag = true;
		}
		if (flag) break;
	}
	cout << (flag ? "YES\n" : "NO\n");
	return 0;
}