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