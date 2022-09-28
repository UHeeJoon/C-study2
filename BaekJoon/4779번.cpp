#include<bits/stdc++.h>
using namespace std;
//#define MAX 1<<21
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
void DivideNConquer(int n) {
	if (!n) {
		cout << '-';
		return;
	}
	DivideNConquer(n - 1);
	for (int i = 0; i < (int)pow(3, n - 1); i++)
		cout << ' ';
	DivideNConquer(n - 1);
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	while (cin >> n && !cin.eof()) {
		DivideNConquer(n);
		cout << '\n';
	}
	return 0;
}