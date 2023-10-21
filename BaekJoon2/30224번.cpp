#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	string digit; cin >> digit;
	const bool isInSeven = digit.find('7') != string::npos;
	const bool isDivisibleBySeven = !(stoi(digit) % 7);
	int ans = 0;
	if (!isInSeven && isDivisibleBySeven)
	{
		ans = 1;
	}
	else if (isInSeven && !isDivisibleBySeven)
	{
		ans = 2;
	}
	else if (isInSeven && isDivisibleBySeven)
	{
		ans = 3;
	}
	cout << ans << '\n';
	return 0;
}