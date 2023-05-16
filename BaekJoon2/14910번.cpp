#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	string message = "Good\n";
	int tmp = -987654321;
	int num;
	while (cin >> num && !cin.eof())
	{
		if (tmp > num)
		{
			message = "Bad\n";
		}
		tmp = num;
	}
	cout << message;
	return 0;
}