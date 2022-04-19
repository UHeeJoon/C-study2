#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; 
	while (t--) {
		int n; cin >> n;
		int cnt = 0, cnt2 = 0;
		while (n--){
			char a, b; cin >> a >> b;
			if (a == 'R' && b == 'S' || a == 'P' && b == 'R' || a == 'S' && b == 'P')
				cnt++;
			else if (a == b) continue;
			else
				cnt2++;
		}
		if (cnt == cnt2)
			cout << "TIE\n";
		else if (cnt > cnt2)
			cout << "Player 1\n";
		else
			cout << "Player 2\n";
	}
	return 0;
}