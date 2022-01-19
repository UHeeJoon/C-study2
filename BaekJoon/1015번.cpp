#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vt;
vector<int> vt2;
int n;
int main() {
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vt.push_back(tmp);
		vt2.push_back(tmp);
	}

	sort(vt.begin(), vt.end());
	for (int i = 0; i < (int)vt2.size(); i++) {
		tmp = (int)(find(vt.begin(), vt.end(), vt2[i]) - vt.begin());
		cout << tmp << " ";
		vt[tmp] = 0;
	}
}