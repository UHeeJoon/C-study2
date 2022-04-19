#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		double speed; int weight, strength; cin >> speed >> weight >> strength;
		if (speed == 0 && weight == 0 && strength == 0)break;
		int cnt = 0;
		if (speed <= 4.5 && weight >= 150 && strength >= 200) {
			cout << "Wide Receiver ";
			cnt++;
		}
		if (speed <= 6.0 && weight >= 300 && strength >= 500) {
			cout << "Lineman ";
			cnt++;
		}
		if (speed <= 5.0 && weight >= 200 && strength >= 300) {
			cout << "Quarterback ";
			cnt++;
		}
		if (cnt == 0)
			cout << "No positions";
		cout << '\n';
	}
	return 0;
}