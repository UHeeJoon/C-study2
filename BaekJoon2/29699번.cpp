#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	string str = "WelcomeToSMUPC";
	string::size_type len = str.length();
	int n; cin >> n;
	string::size_type idx = (len + n % len - 1) % len;
	cout << str[idx] << '\n';
	return 0;
}