#include<iostream>
using namespace std;
int n, kim, im, ret;
void fight(int kim, int im, int cnt) {
	if (kim == im) {
		ret = cnt;
		return;
	}
	kim & 1 ? kim += 1 : kim;
	im & 1 ? im += 1 : im;
	fight(kim / 2, im / 2, cnt + 1);
}
int main() {
	cin >> n >> kim >> im;		
	fight(kim, im, 0);
	cout << ret;
}