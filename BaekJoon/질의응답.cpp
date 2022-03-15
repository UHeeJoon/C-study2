#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
int sub(int n) {
	//if (n < 0)
	//	return 0;
	//return n + sub(n - 3);
	int sum(0);
	for (int i = n; i > 0; i -= 3)
		sum += i;
	return sum;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	int n; cin >> n;
	cout << sub(10) << '\n';
	//22
	return 0;
}