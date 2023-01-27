#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
long long fibonacci[117];
int main() {
	FAST_IO;
	int n; cin >> n;
	fibonacci[1] = fibonacci[2] = fibonacci[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 3];
	}
	cout << fibonacci[n] << '\n';
	return 0;
}