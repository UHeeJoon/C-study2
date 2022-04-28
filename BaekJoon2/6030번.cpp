#include<bits/stdc++.h>
using namespace std;
vector<int> GCD(int x) {
	vector<int> v;
	int tmp = x;
	for (int i = 1; i <= tmp; i++) {
		if (x % i == 0) {
			if(find(v.begin(), v.end(), tmp) == v.end())
				v.push_back(tmp);
			if (find(v.begin(), v.end(), i) == v.end())
				v.push_back(i);
			tmp = x / i;
		}
	}
	return v;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;	cin >> a >> b;
	vector<int> v = GCD(a); sort(v.begin(), v.end());
	vector<int> v2= GCD(b); sort(v2.begin(), v2.end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			cout << v[i] << ' ' << v2[j] << '\n';
		}
	}
	return 0;
}