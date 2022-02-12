#include<iostream>
#include<stack>
#include<string>
using namespace std;
int n, num;
string s;
stack<int> stk;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> s;
		if (s[0] == 'p' && s[1] == 'u') {
			cin >> num;
			stk.push(num);
		}
		else if (s[0] == 's') {
			cout << stk.size() << "\n";
		}
		else if (s[0] == 'e') {
			cout << stk.empty() << "\n";
		}
		else if (s[0] == 't') {
			int t = (int)stk.size() == 0 ? -1 : stk.top();
			cout << t << "\n";
		}
		else {
			int t = (int)stk.size() == 0 ? -1 : stk.top();
			if (t == -1) {
				cout << -1 << "\n";
				continue;
			}
			stk.pop();
			cout << t << "\n";
		}
	}
	return 0;
}