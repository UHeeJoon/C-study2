#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	for (;;)
	{
		const string nemo = "NEMO";
		string str;
		getline(cin, str, '\n');
		if (str == "EOI") { break; }
		for_each(str.begin(), str.end(), [](char& c) -> void {c = static_cast<char>(toupper(c)); });
		string isHasNemo = str.find(nemo) != string::npos ? "Found\n" : "Missing\n";
		cout << isHasNemo;
	}
	return 0;
}