#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int num; cin >> num;
	bool flag = true;
	bool visited[800] = { false, };
	while (true)
	{
		int tmp = 0;
		while (num)
		{
			tmp += static_cast<int>(pow(num % 10, 2));
			num /= 10;
		}
		if (tmp == 1)
		{
			break;
		}
		if (visited[tmp])
		{
			flag = false;
			break;
		}
		visited[tmp] = true;
		num = tmp;
	}
	cout << (flag ? "HAPPY\n" : "UNHAPPY\n");
	return 0;
}