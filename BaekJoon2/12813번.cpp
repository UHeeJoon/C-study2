#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	string b1, b2;
	cin >> b1 >> b2;
	string ans[5] = { "", };
	for (string::size_type i = 0; i < b1.length(); i++)
	{
		const char a_and_b = b1[i] == '1' && b2[i] == '1' ? '1' : '0',
			a_or_b = b1[i] == '1' || b2[i] == '1' ? '1' : '0',
			a_xor_b = b1[i] != b2[i] ? '1' : '0',
			not_a = b1[i] == '0' ? '1' : '0',
			not_b = b2[i] == '0' ? '1' : '0';
		ans[0] += a_and_b;
		ans[1] += a_or_b;
		ans[2] += a_xor_b;
		ans[3] += not_a;
		ans[4] += not_b;
	}
	for (const string& str : ans)
	{
		cout << str << '\n';
	}
	return 0;
}

/*

#include <iostream>
#include <string.h>

#define Sync ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define in cin >>
#define out cout <<
#define endl << "\n"
#define Fori(x) for (int i = 0; i < x; i++)

using namespace std;

char a[100001], b[100001], ret[100001];

int main() {
	Sync;

	in a >> b;
	int s = strlen(a);

	Fori(s) ret[i] = (a[i] & b[i]); out ret endl;
	Fori(s) ret[i] = (a[i] | b[i]); out ret endl;
	Fori(s) ret[i] = (a[i] == b[i] ? '0' : '1'); out ret endl;
	Fori(s) ret[i] = (a[i] == '1' ? '0' : '1'); out ret endl;
	Fori(s) ret[i] = (b[i] == '1' ? '0' : '1'); out ret endl;
}
 
 */