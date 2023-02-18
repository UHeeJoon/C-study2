#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef long long ll;
ll gcd(const ll a, const ll b)
{
	return b ? gcd(b, a % b) : a;
}
int main()
{
	FAST_IO;
	int tc; cin >> tc;
	while (tc--)
	{
		ll a, b; cin >> a >> b;
		cout << (a * b) / gcd(a, b) << '\n';
	}
	return 0;
}