#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef long long ll;
bool calculate(const vector<int>& v, const ll mid, const ll k)
{
	ll sum = 0;
	for (const int num : v)
	{
		if (num >= mid) { break; }
		if (sum > k) { break; }
		sum += (mid - num);
	}
	return sum <= k;
}
int binary_search(const vector<int>& v, const int k)
{
	int left = v[0], right = v[v.size() - 1] + k;
	int ans = 0;
	while (left <= right)
	{
		const int mid = (left + right) / 2;
		if (calculate(v, mid, k))
		{
			left = mid + 1;
			ans = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	return ans;
}
int main()
{
	FAST_IO;
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for_each(v.begin(), v.end(), [](int& num) {cin >> num; });
	sort(v.begin(), v.end());
	cout << binary_search(v, k);
	return 0;
}