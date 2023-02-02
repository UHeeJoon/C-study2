#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main() {
	FAST_IO;
	int n, m, l; cin >> n >> m >> l;
	vector<int> friends(n + 1);
	int me = 0;
	int count = 0;
	while (true)
	{
		friends[me]++;
		if (friends[me] == m)break;
		me = friends[me] & 1 ? (me + l) % n : (me + n - l) % n;
		count++;
	}
	cout << count << '\n';
	return 0;
}