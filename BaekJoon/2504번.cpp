#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	stack<char> stk;
	string s; cin >> s;
	int sum = 0, tmp = 1;
	bool isTrue = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			stk.push(s[i]);
			tmp *= 2;
		}
		else if (s[i] == '[') {
			stk.push(s[i]);
			tmp *= 3;
		}
		else if (s[i] == ')') {
			if ((stk.empty() || stk.top() != '(')) {
				isTrue = false;
				break;
			}
			else {
				if (s[i - 1] == '(')
					sum += tmp;
				tmp /= 2;
				stk.pop();
			}
		}
		else if (s[i] == ']') {
			if ((stk.empty() || stk.top() != '[')) {
				isTrue = false;
				break;
			}
			else {
				if (s[i - 1] == '[')
					sum += tmp;
				tmp /= 3;
				stk.pop();
			}
		}

	}
	if (isTrue && stk.empty())
		cout << sum << '\n';
	else
		cout << 0 << '\n';
	return 0;
}