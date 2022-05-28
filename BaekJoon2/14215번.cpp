#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tri[3] = { 0, };
	cin >> tri[0] >> tri[1] >> tri[2];
	sort(tri, tri + 3);
	if (tri[2] >= tri[0] + tri[1])
		tri[2] = tri[0] + tri[1] - 1;
	cout << tri[0] + tri[1] + tri[2] << '\n';
	return 0;
}