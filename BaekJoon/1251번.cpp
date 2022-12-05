#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str; cin >> str;
	vector<string> v;
	for (int i = 0; i < str.length() - 2; i++) {
		for (int j = i + 1; j < str.length() - 1; j++) {
			for (int k = j + 1; k < str.length(); k++) {
				string first = str.substr(0, j);
				string second = str.substr(j, k - j);
				string third = str.substr(k);
				reverse(first.begin(), first.end());
				reverse(second.begin(), second.end());
				reverse(third.begin(), third.end());
				v.push_back(first + second + third);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v[0] << '\n';
	return 0;
}