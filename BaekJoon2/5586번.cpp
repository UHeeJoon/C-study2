#include<bits/stdc++.h>
using namespace std;
int findJOI(string str) {
	int res = 0, p, i = 0, count = 0;
	while (1) {
		p = str.find("JOI", i);
		if (p == -1)break;
		else {
			i = p + 2; count++;
		}
	}
	return count;
}
int findIOI(string str) {
	int res = 0, p, i = 0, count = 0;
	while (1) {
		p = str.find("IOI", i);
		if (p == -1)break;
		else {
			i = p + 2;
			count++;
		}
	}
	return count;
}
int main() {
	string s; 
	int resx, resy;
	cin >> s;
	resx = findJOI(s);
	resy = findIOI(s);
	cout << resx << "\n" << resy << '\n';
}