#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
static int search(string& str, const int col, const int k) {
	int	count = 0;
	vector<int> v(col + 1, 0);
	for (vector<int>::size_type i = 1; i <= col; i++) {
		v[i] = v[i - 1] + str[i - 1] - '0';
	}
	for (vector<int>::size_type i = k; i <= col; i++) {
		if (v[i] - v[i - k]) { continue; }
		count++;
	}
	return count;
}
int main()
{
	FAST_IO;
	int row, col, k;
	cin >> row >> col >> k;
	int sum = 0;
	for (int i = 0; i < row; i++) {
		string str; cin >> str;
		sum += search(str, col, k);
	}
	cout << sum << '\n';
	return 0;
