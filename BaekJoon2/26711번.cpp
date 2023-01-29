#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main() {
	FAST_IO;
	string s1, s2; cin >> s1 >> s2;
	int s1_len = static_cast<int>(s1.length());
	int s2_len = static_cast<int>(s2.length());
	string answer = "";
	int digit = 0;
	while (s1_len || s2_len)
	{
		int sum = 0;
		if (s1_len)
		{
			s1_len--;
			sum += (s1[s1_len] - '0');
		}
		if (s2_len)
		{
			s2_len--;
			sum += (s2[s2_len] - '0');
		}
		sum += digit;
		answer.push_back(static_cast<char>(sum % 10 + '0'));
		digit = sum / 10;
	}
	if (digit != 0)answer.push_back(static_cast<char>(digit + '0'));
	reverse(answer.begin(), answer.end());
	cout << answer << '\n';
	return 0;
}