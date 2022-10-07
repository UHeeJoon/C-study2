#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
//#define MAX 1005
//#define INF 2'100'000'000
//#define MOD 1000
//typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int arr = 3, tmp = 4;
	while (1) {
		arr = arr * 2 + tmp;
		if (arr >= n)break;
		tmp++;
	}
	if (arr == n) {
		cout << "o\n";
	}
	else {
		arr -= tmp;
		arr /= 2;

	}
	return 0;
}