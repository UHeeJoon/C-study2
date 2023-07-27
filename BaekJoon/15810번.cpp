#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef long long ll;
ll calculate(const vector<int>& v, const ll mid)
{
	ll ans = 0;
	for_each(v.begin(), v.end(), [&ans, mid](const int num) { ans += mid / num; });
	return ans;
}
ll binary_search(const vector<int>& v, const int m)
{
	ll left = 0;
	ll right = 1'000'000'000'000L;
	while (left < right)
	{
		const ll mid = (left + right) / 2;
		if (calculate(v, mid) >= m)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}

	}
	return left;
}
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	vector<int>v(n);
	for (int& num : v)
	{
		cin >> num;
	}
	sort(v.begin(), v.end());
	cout << binary_search(v, m) << '\n';
	return 0;
}