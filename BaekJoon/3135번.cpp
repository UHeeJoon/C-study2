#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b; cin >> a >> b;
	int button = abs(a - b);
	int n; cin >> n;
	while (n--) {
		int num; cin >> num;
		button = min(abs(num - b) + 1, button);
	}
	cout << button << '\n';
	return 0;
}