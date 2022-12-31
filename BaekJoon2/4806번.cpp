#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	int count = 0;
	while (getline(cin, str) && !cin.eof()) { count++; }
	cout << count << '\n';
	return 0;
}