#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bool arr[102] = { 0, };
	int n; cin >> n;
	int cnt(0);
	while (n--) {
		int num; cin >> num;
		if (!arr[num])arr[num] = true;
		else cnt++;
	}
	cout << cnt << '\n';
	return 0;
}