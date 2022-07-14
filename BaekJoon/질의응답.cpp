#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int JOI = 0, IOI = 0;
	string s; cin >> s;
	int slen = s.length();
	for (int i = 0; i < slen - 2; i++) {
		if (s.substr(i, 3) == "JOI") JOI++;
		else if (s.substr(i, 3) == "IOI") IOI++;
	}

	cout << JOI << '\n' << IOI << '\n';
	return 0;
}

