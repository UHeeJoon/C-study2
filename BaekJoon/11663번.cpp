#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef long long ll;

int binary_search(const vector<int>& v, const int location_x, const int location_y)
{
	auto x = lower_bound(v.begin(), v.end(), location_x) - v.begin();
	auto y = upper_bound(v.begin(), v.end(), location_y) - v.begin();
	return y - x;
}
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	vector<int> v(n);
	for_each(v.begin(), v.end(), [](int& num) {cin >> num; });
	sort(v.begin(), v.end());
	while (m--)
	{
		int location_x, location_y;
		cin >> location_x >> location_y;
		cout << binary_search(v, location_x, location_y) << '\n';
	}
	return 0;
}
