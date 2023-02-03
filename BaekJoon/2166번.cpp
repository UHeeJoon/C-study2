#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
vector<pair<double, double>> points;
int main() {
	FAST_IO;
	cout.precision(1); cout << fixed;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		points.emplace_back(x, y);
	}
	points.emplace_back(points[0].first, points[0].second);
	double answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer += points[i].first * points[i + 1].second - points[i].second * points[i + 1].first;
	}
	answer = answer < 0 ? -answer : answer;
	cout << answer / 2 << '\n';
	return 0;
}