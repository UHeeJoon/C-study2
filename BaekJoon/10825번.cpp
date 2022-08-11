#include<bits/stdc++.h>
using namespace std;
struct STUDENT {
	string name;
	int kor;
	int eng;
	int math;
};
bool comp(STUDENT a, STUDENT b) {
	if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
	if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
	if (a.kor == b.kor) return a.eng < b.eng;
	return a.kor > b.kor;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<STUDENT> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}
	sort(v.begin(), v.end(), comp);
	for (auto a : v)
		cout << a.name << '\n';

	return 0;
}