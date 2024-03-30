#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main()
{
	FAST_IO;
	bool flag = false;
	vector<vector<string>> v(10, vector<string>(10));
	for (int i = 0; i < 10; i++) {
		bool check = true;
		for (int j = 0; j < 10; j++) {
			cin >> v[i][j];
			//가로 체크
			if (j > 0 && v[i][0] != v[i][j]) { check = false; }
			//마지막 줄 확인시 세로 체크
			if (i == 9) {
				bool check2 = true;
				for (int k = i - 1; k >= 0; k--) {
					if (v[i][j] != v[k][j]) { check2 = false; }
				}
				if (!flag) {
					flag = check2;
				}
			}
		}
		if (!flag) {
			flag = check;
		}
	}
	cout << flag << '\n';
	return 0;
}