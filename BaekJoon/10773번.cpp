#include<iostream>
#include<stack>
using namespace std;
int k, num, _sum;
stack<int> stk;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> k;
	while (k--) {
		cin >> num;
		if (num == 0) {
			_sum -= stk.top();
			stk.pop();
			continue;
		}
		stk.push(num);
		_sum += stk.top();
	}
	cout << _sum << "\n";
	return 0;
}