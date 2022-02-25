#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	int cnt = 1;	
	getline(cin,s);
	for (int i = 1; i < (int)s.length() - 1; i++) {
		if (s[i] == ' ') cnt++;
	}
	if (s == " ") cnt--;
	cout << cnt << '\n';
}