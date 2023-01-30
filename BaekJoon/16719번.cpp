#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void make_rule(const string& str, const int start, const int end, const int index, string& answer)
{
	if (start > end)return;
	char tmp = str[start]; int idx = start;
	for (int i = start + 1; i <= end; i++)
	{
		if (str[i] < tmp)
		{
			tmp = str[i];
			idx = i;
		}
	}
	const int answer_len = static_cast<int>(answer.length());
	const string f{ answer.begin(), answer.end() - (answer_len - index) };
	const string b{ answer.begin() + index, answer.end() };
	answer = f + tmp + b;
	cout << answer << '\n';
	make_rule(str, idx + 1, end, index + 1, answer);
	make_rule(str, start, idx - 1, index, answer);
}
int main() {
	FAST_IO;
	string str; cin >> str;
	string answer = "";
	make_rule(str, 0, static_cast<int>(str.length() - 1), 0, answer);
	return 0;
}


/*
 * 다른 사람 풀이 
#include <iostream>

using namespace std;

string str;
bool zoac[100];

void printZoacOrder(int left, int right) {
	char minChar = str.at(left);
	int minIdx = left;
	for (int i = left + 1; i <= right; ++i) {
		char c = str.at(i);
		if (minChar > c) {
			minChar = c;
			minIdx = i;
		}
	}
	zoac[minIdx] = true;
	for (int i = 0; i < (int)str.length(); ++i) {
		if (zoac[i]) {
			cout << str.at(i);
		}
	}
	cout << "\n";
	if (minIdx < right) {
		printZoacOrder(minIdx + 1, right);
	}
	if (minIdx > left) {
		printZoacOrder(left, minIdx - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	printZoacOrder(0, (int)str.length() - 1);
	return 0;
}

 */