#include<bits/stdc++.h>
using namespace std;
#define MAX 25
#define INF 2147483647
bool gear[6][9];
int k, score;
void move(int curGearNum, int direction) {
	bool tmpGear[9] = { 0, };
	copy(gear[curGearNum], gear[curGearNum] + 9, tmpGear);
	if (direction == 1) {
		for (int i = 0; i < 8; i++) {
			gear[curGearNum][(i + 1) % 8] = tmpGear[i];
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			gear[curGearNum][(i + 7) % 8] = tmpGear[i];
		}
	}
	return;
}
void rightCheck(int curGearNum, int direction) {
	int nextGearNum = curGearNum + 1;
	if (nextGearNum == 5) return;
	if (gear[curGearNum][2] != gear[nextGearNum][6]) {
		rightCheck(nextGearNum, -direction);
		move(nextGearNum, -direction);
	}
	return;
}
void leftCheck(int curGearNum, int direction) {
	int nextGearNum = curGearNum - 1;
	if (nextGearNum == 0) return;
	if (gear[curGearNum][6] != gear[nextGearNum][2]) {
		leftCheck(nextGearNum, -direction);
		move(nextGearNum, -direction);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			char pole; cin >> pole;
			gear[i][j] = pole - '0';
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int gearNum, direction; cin >> gearNum >> direction;
		rightCheck(gearNum, direction);
		leftCheck(gearNum, direction);
		move(gearNum, direction);
		//cout << '\n';
		//for (int i = 1; i <= 4; i++) {
		//	for (int j = 0; j < 8; j++) {
		//		cout << gear[i][j];
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
	}
	for (int i = 1; i <= 4; i++) {
		if (gear[i][0]) score += (1 << (i - 1));
	}
	cout << score << '\n';
	return 0;
}