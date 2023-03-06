#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n; cin >> n;
	vector<int> v(n);
	vector<int> tmp;
	for (int i = 0; i < n; i++) v[i] = i + 1;
	while (static_cast<int>(v.size()) > 1)
	{
		vector<int>().swap(tmp);
		for (int i = 1; i < static_cast<int>(v.size()); i += 2) tmp.push_back(v[i]);
		v.swap(tmp);
	}
	cout << v[0] << '\n';
	return 0;
}