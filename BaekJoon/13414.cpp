#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
typedef vector<pair<string, int>>::size_type vt;
typedef pair<string, int> std_code;
bool compare(const std_code& a, const std_code& b) {
	return a.second < b.second;
}
int main()
{
	FAST_IO;
	vt k;
	unordered_map<string, int> student;
	int l;
	cin >> k >> l;

	for (int i = 0; i < l; i++) {
		string number;
		cin >> number;
		student[number] = i;
	}

	vector<std_code> v(student.size());
	int idx = 0;
	for (const std_code i : student)
	{
		v[idx++] = i;
	}

	sort(v.begin(), v.end(), compare);
	for (vt i = 0; i < min(k, v.size()); i++)
		cout << v[i].first << '\n';
	return 0;
}