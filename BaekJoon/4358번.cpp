#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	cout.precision(4); cout << fixed;
	map<string, int> wood;
	string str;
	double len = 0.0;
	while (getline(cin, str) && !cin.eof())
	{
		wood[str]++;
		len++;
	}

	for (const auto& element : wood)
	{
		cout << element.first << ' ' << element.second * 100.0 / len << '\n';
	}
	cout << '\n';
	return 0;
}