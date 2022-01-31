#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	stack <int> stk;
	vector<char> v;
	int cnt = 1;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		while (cnt <= num) {
			stk.push(cnt);
			cnt += 1;
			v.push_back('+');
		}
		if (stk.top() == num) {
			stk.pop();
			v.push_back('-');
		}
		else {
			cout << "NO\n";
			return 0; 
		}
	}
	for (int i = 0; i < (int)v.size(); i++)
		cout << v[i] << "\n";
	return 0;
}