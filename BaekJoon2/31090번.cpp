#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int tc; cin >> tc;
	while (tc--) {
		int year; cin >> year;
		int divide_num = year % 100;
		cout << ((year + 1) % divide_num == 0 ? "Good\n" : "Bye\n");
	}
	return 0;
}