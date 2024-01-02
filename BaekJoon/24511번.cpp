#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int v[100000];
int main()
{
	FAST_IO;
	deque<int> dq;
	int n; cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v[i] = num;
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (!v[i]) {
			dq.push_back(num);
		}
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		dq.push_front(num);
		v[i] = dq.back();
		dq.pop_back();
	}
	for (int i = 0; i < m; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
	return 0;
}