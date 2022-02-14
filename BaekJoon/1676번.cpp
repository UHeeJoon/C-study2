#include<iostream>
using namespace std;
int n, f, cnt;
void Five(int five) {
	while (five) {
		if (five % 5 != 0)
			return;
		five /= 5;
		cnt++;
	}
}
int main() {
	cin >> n;
	while (n--)
		Five(n + 1);
	cout << cnt << "\n";
}