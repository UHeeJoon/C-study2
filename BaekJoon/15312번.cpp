#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	constexpr int alphabet[] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
	vector<int> score;
	string name[2];
	for (string& who : name)
	{
		cin >> who;
	}
	for (string::size_type i = 0; i < name[0].length(); i++)
	{
		score.push_back(alphabet[name[0][i] - 'A']);
		score.push_back(alphabet[name[1][i] - 'A']);
	}
	while (score.size() > 2)
	{
		vector<int> tmp;
		for (vector<int>::size_type i = 0; i < score.size() - 1; i++)
		{
			tmp.push_back((score[i] + score[i + 1]) % 10);
		}
		score.swap(tmp);
	}
	for (const int num : score)
	{
		cout << num;
	}
	cout << '\n';
	return 0;
}