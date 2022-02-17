/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n, d[200001], ret, cnt;
string s;
stack<int> stk;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') stk.push(i);
		else if (stk.size()) {
			d[i] = d[stk.top()] = 1;
			stk.pop();
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i]) {
			cnt++;
			ret = max(ret, cnt);
		}
		else cnt = 0;
	}
	cout << ret << "\n";
}
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;
int n, cnt, ret;
string str;
stack<int> s;
int main() {
	cin >> n;
	cin >> str;
	s.push(-1);
	for (int i = 0; i < n; i++) {
		if (str[i] == '(') s.push(i);
		if (str[i] == ')') {
			s.pop();
			if (!s.empty()) {
				ret = max(ret, i - s.top());
			}
			else {
				s.push(i);
			}
		}
	}
	cout << ret << '\n';
	return 0;
}
