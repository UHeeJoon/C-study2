#include<iostream>
#include<string>
using namespace std;
int n, cnt;
string s;
bool color[500001];

void check(char c) {

}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) 
		if (s[i] == 'R')
			color[i] = 1;
	cout << cnt << "\n";
}