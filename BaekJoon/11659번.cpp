#include<iostream>
using namespace std;
int num[100010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		num[i] = num[i - 1] + tmp;
	}
	for (int i = 0; i < m; i++) {
		int _left, _right; cin >> _left >> _right;
		cout << num[_right] - num[_left - 1] << '\n';
	}
}