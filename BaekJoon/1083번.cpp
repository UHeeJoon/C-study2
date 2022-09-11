#include<bits/stdc++.h>
using namespace std;
//#define MAX 1010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num[51] = { 0, };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	int k; cin >> k;
	for (int i = 0; i < n; i++) {
		if (k == 0)break;
		int _max = num[i], maxIdx = i;
		for (int j = i + 1; j < n && j <= i + k; j++) {
			if (_max < num[j]) {
				_max = num[j];
				maxIdx = j;
			}
		}
		k -= maxIdx - i;
		while (maxIdx > i) {
			num[maxIdx] = num[maxIdx - 1];
			maxIdx--;
		}
		num[i] = _max;
	}
	for (int i = 0; i < n; i++) {
		cout << num[i] << ' ';
	}
	cout << '\n';
	return 0;
}