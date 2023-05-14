#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int s1, s2; cin >> s1 >> s2;
	cout << (s1 ^ s2) << '\n';
	return 0;
}