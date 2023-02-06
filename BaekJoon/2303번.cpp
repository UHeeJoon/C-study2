#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int cal_sum(int arr[])
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (i == j || i == k || j == k)continue;
				sum = max(sum, (arr[i] + arr[j] + arr[k]) % 10);
			}
		}
	}
	return sum;
}
int main() {
	FAST_IO;
	int n; cin >> n;
	int answer_sum = 0;
	int answer_idx = 0;
	for (int i = 1; i <= n; i++)
	{
		int arr[5] = { 0, };
		for (int& a : arr)
		{
			cin >> a;
		}
		const int sum = cal_sum(arr);
		if (sum >= answer_sum)
		{
			answer_sum = sum;
			answer_idx = i;
		}

	}
	cout << answer_idx << '\n';
	return 0;
}