#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'000 + 10
//#define INF 2'100'000'000
//#define MOD 1000
//typedef unsigned long long ull;
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int cnt = 0;
	while (n--) {
		string str; cin >> str;
		if (str.find("CD") == string::npos)cnt++;
	}
	cout << cnt << '\n';

	return 0;
}
