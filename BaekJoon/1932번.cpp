#include<bits/stdc++.h>	
using namespace std;
int n, sum;
vector<int> v[501];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int tmp; cin >> tmp;
			v[i].push_back(tmp);
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			if (j == 0)
				v[i][j] += v[i - 1][j];
			else if (j == (int)v[i].size() - 1)
				v[i][j] += v[i - 1][j - 1];
			else {
				v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
			}
		}
	}
	for (int i = 0; i < (int)v[n - 1].size(); i++)
		sum = max(sum, v[n - 1][i]);
	cout << sum << '\n';
	return 0;
}