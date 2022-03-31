#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed; cout.precision(1);
	string s; cin >> s;
	double gdp(0);
	if (s[0] == 'A') gdp = 4.0;
	else if (s[0] == 'B') gdp = 3.0;
	else if (s[0] == 'C') gdp = 2.0;
	else if (s[0] == 'D') gdp = 1.0;
	else gdp = 0.0;
	if (s[1] == '+')gdp += 0.3;
	else if (s[1] == '-') gdp -= 0.3;
	else if (s[1] == '0');
	else;
	cout << gdp << '\n';
	return 0;
}