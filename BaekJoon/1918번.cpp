#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str; cin >> str;
	stack<char> op;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << str[i];
		}
		else {
			if (str[i] == '+' || str[i] == '-') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/') {
				while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
					cout << op.top();
					op.pop();
				}
				op.push(str[i]);
			}
			else if (str[i] == '(') {
				op.push(str[i]);
			}
			else if (str[i] == ')') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
	return 0;
}