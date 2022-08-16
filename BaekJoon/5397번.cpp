#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		stack<int> stk, tmp;
		string s; cin >> s;
		string left = "", right = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<') {
				if (stk.empty())continue;
				tmp.push(stk.top());
				stk.pop();
			}
			else if (s[i] == '>') {
				if (tmp.empty())continue;
				stk.push(tmp.top());
				tmp.pop();
			}
			else if (s[i] == '-') {
				if (stk.empty())continue;
				stk.pop();
			}
			else
				stk.push(s[i]);
		}
		while (!stk.empty() || !tmp.empty()) {
			if (!stk.empty()) {
				left += stk.top();
				stk.pop();
			}
			if (!tmp.empty()) {
				right += tmp.top();
				tmp.pop();
			}
		}
		reverse(left.begin(), left.end());
		cout << left + right << '\n';
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		list<char> L = {};
		string s1;
		auto p = L.begin();
		cin >> s1;
		for (auto c : s1) {

			if (c == '<') {
				if (p != L.begin()) p--;

			}
			else if (c == '>') {
				if (p != L.end()) p++;


			}
			else if (c == '-') {
				if (p != L.begin()) {
					p--;
					p = L.erase(p);
				}
			}
			else {
				L.insert(p, c);
			}
		}
		for (auto c : L)    cout << c;
		cout << '\n';
	}
}
*/