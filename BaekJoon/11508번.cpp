#include<bits/stdc++.h>
using namespace std;
//#define MAX 200'010
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0;
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < n; i++)
		if (i % 3 != 2) sum += v[i];
	cout << sum << '\n';
	return 0;
}