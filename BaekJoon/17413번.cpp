#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s, ret = "", tmp = "", tmp2 = "";
	getline(cin, s);
	bool flag = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<') {
			flag = false;
			ret += tmp2;
			tmp2 = "";
		}
		else if (s[i] == '>') {
			flag = true;
			tmp += s[i];
			ret += tmp;
			tmp = "";
			continue;
		}

		if (flag) {
			if (s[i] == ' ') {
				ret = ret + tmp2 + ' ';
				tmp2 = "";
			}
			else
				tmp2 = s[i] + tmp2;
		}
		else {
			tmp += s[i];
		}
	}
	if (tmp2.size() != 0)ret += tmp2;
	cout << ret << '\n';
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s = "";
	getline(cin, s);
	s += '\n';
	stack<char> st;
	bool check = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			while (!st.empty()) {
				printf("%c", st.top());
				st.pop();
			}
			printf("<");
			check = true;
		}
		else if (s[i] == '>') {
			printf(">");
			check = false;
		}
		else if (check) printf("%c", s[i]);

		else if (s[i] == ' ' || s[i] == '\n') {
			while (!st.empty()) {
				printf("%c", st.top());
				st.pop();
			}
			printf(" ");
		}
		else st.push(s[i]);
	}
	return 0;
}

*/