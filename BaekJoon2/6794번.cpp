#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	bool check[6] = { 0, };
	int cnt = 0;
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++)
			if (i + j == n) check[i] = true;
	for (int i = 0; i <= n / 2; i++)
		if (check[i]) cnt++;
	cout << cnt <<'\n';
	return 0;
}