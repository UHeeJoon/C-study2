#include<bits/stdc++.h>
using namespace std;
bool bingo[6][6];
int number[26];
bool check() {
	int cnt = 0;
	if (bingo[0][0] && bingo[1][1] && bingo[2][2] && bingo[3][3] && bingo[4][4])cnt++;
	if (bingo[4][0] && bingo[3][1] && bingo[2][2] && bingo[1][3] && bingo[0][4])cnt++;
	for (int i = 0; i < 5; i++) {
		int cnt2 = 0;
		for (int j = 0; j < 5; j++) {
			if (!bingo[i][j])break;
			else cnt2++;
		}
		if (cnt2 == 5) {
			cnt++;
			if (cnt >= 3)return true;
		}
		cnt2 = 0;
		for (int j = 0; j < 5; j++) {
			if (!bingo[j][i])break;
			else cnt2++;
		}
		if (cnt2 == 5) {
			cnt++;
			if (cnt >= 3)return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int num; cin >> num;
			number[num] = i * 10 + j;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int num; cin >> num;
			int idx = number[num];
			bingo[idx / 10][idx % 10] = true;
			if (!check()) {
				cnt++;
			}
		}
	}

	cout << cnt + 1 << '\n';
	return 0;
}