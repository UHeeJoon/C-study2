#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b) {
	return a % b == 0 ? b : GCD(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	int idx = (int)s.find(":");
	int num1 = stoi(s.substr(0, idx));
	int num2 = stoi(s.substr(idx + 1));
	int gcd = GCD(num1, num2);
	cout << num1 / gcd << ':' << num2 / gcd << '\n';
	return 0;
}