#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int N, sum = 0;
	double total = 0.0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string name, score;
		int times;
		double subject_score = 0.0;

		cin >> name >> times >> score;

		if (score[0] != 'F')
		{
			subject_score += 'E' - score[0];
			subject_score += 0.3 * (score[1] == '+');
			subject_score -= 0.3 * (score[1] == '-');
		}

		sum += times;
		total += subject_score * times;
	}

	total /= sum;
	total *= 1000;
	total += static_cast<int>(total) % 10 > 4;
	total /= 1000;
	cout.precision(2);
	cout << fixed;
	cout << total;
	return 0;
}
