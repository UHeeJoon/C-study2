#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	char c; cin >> c;
	char ans[10] = { '\0', };
	switch (c)
	{
	case 'M': strcpy_s(ans, "MatKor"); break;
	case 'W': strcpy_s(ans, "WiCys"); break;
	case 'C': strcpy_s(ans, "CyKor"); break;
	case 'A': strcpy_s(ans, "AlKor"); break;
	case '$': strcpy_s(ans, "$clear"); break;
	default: ans[0] = '\0';
	}
	cout << ans << '\n';
	return 0;
}