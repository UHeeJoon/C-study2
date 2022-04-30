#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string team1 = "", team2 = "";
	int n, t1(1), t2(0); cin >> n;
	cin >> team1;
	for (int i = 1; i < n; i++) {
		string tmp; cin >> tmp;
		if (tmp == team1) {
			team1 = tmp;
			t1++;
		}
		else {
			team2 = tmp;
			t2++;
		}
	}
	cout << (t1 > t2 ? team1 : team2) << '\n';
	return 0;
}