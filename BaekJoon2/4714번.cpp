#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2); cout << fixed;
	while (1) {
		double weight; cin >> weight;
		if (weight < 0.0)break;
		cout << "Objects weighing " << weight << " on Earth will weigh " << weight * 0.167 << " on the moon.\n";
	}
	return 0;
}