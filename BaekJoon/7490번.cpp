#include<bits/stdc++.h>
using namespace std;
int calculate(const int num1, const char& op, const int num2)
{
	if (op == '+') return num1 + num2;
	return num1 - num2;
}
void back_tracking(vector<string>& answer, const int num, const int idx, const string& operate)
{
	if (idx == num)
	{
		string formula = "1";
		int sum = 1;
		int tmp = 2;
		for (int i = 0; i < static_cast<int>(operate.length()); i++)
		{
			formula += operate[i] + to_string(tmp);
			if (operate[i] == ' ')
			{
				if (i == 0 || operate[i - 1] == ' ')
				{
					sum = sum * 10 + tmp;
				}
				else
				{
					sum = calculate(sum, operate[i - 1] == '+' ? '-' : '+', tmp - 1);
					sum = calculate(sum, operate[i - 1], (tmp - 1) * 10 + tmp);
				}
			}
			else
			{
				sum = calculate(sum, operate[i], tmp);
			}
			tmp++;
		}
		if (sum == 0)
		{
			answer.push_back(formula);
		}

		return;
	}
	for (const string op : {"+", " ", "-"})
	{
		back_tracking(answer, num, idx + 1, operate + op);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int test_case; cin >> test_case;
	while (test_case--)
	{
		int num; cin >> num;
		vector<string>answer;
		back_tracking(answer, num - 1, 0, "");
		sort(answer.begin(), answer.end());
		for (constexpr string ans : answer)
			cout << ans << '\n';
		cout << '\n';
	}
	return 0;
}