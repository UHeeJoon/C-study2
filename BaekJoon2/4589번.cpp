#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	cout << "Gnomes:\n";
	while (t--) {
		vector <int> beard(3);
		for (int i = 0; i < 3; i++) cin >> beard[i];
		if ((beard[1] - beard[0]) * (beard[2] - beard[1]) > 0) cout << "Ordered\n";
		else cout << "Unordered\n";
	}
	return 0;
}