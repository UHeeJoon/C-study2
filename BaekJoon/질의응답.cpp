#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef unsigned long long ull;
//typedef long long ll;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end(), greater<>());
	for (int a : v) cout << a << '\n';
	return 0;
}
