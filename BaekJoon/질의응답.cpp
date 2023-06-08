//#pragma warning(disable : 4996)
//https://www.acmicpc.net/problem/1996
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n; cin >> n;
	vector<int> arr(n);
	for_each(arr.begin(), arr.end(), [](int& el)-> void {cin >> el; });
	long long sum = accumulate(arr.begin(), arr.end(), 0L);
	long long result = 0;
	for_each(arr.begin(), arr.end() - 1, [&result, &sum](const int num)-> void
		{
			sum -= num;
			result += sum * num;
		});
	cout << result << '\n';
	return 0;
}