#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
int n, m;
int result;
vector < pair<int, pair<int, int>>> v;
int parent[MAX];
int getParent(int num) {
	if (num == parent[num])return num;
	return parent[num] = getParent(parent[num]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, cost; cin >> a >> b >> cost;
		v.push_back({ cost,{a, b} });
	}
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		if (!findParent(a, b)) {
			result += cost;
			unionParent(a, b);
		}
	}
	cout << result << '\n';
	return 0;
}