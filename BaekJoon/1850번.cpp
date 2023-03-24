#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef long long ll;
int gcd(const ll a, const ll b)
{
	return b ? gcd(b, a % b) : a;
}
int main()
{
	FAST_IO;
	ll a, b; cin >> a >> b;
	int count = gcd(a, b);
	while (count--)
	{
		cout << 1;
	}
	cout << '\n';
	return 0;
}