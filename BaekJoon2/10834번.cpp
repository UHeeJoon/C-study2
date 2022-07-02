#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, a = 1, b = 1, s, r_num = 1;
	bool r = true;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> s;
		r_num = (r_num / a) * b;
		r = s == 1 ? !r : r; // 꼬인 형태면 방향이 반대
	}

	if (r) cout << "0 " << r_num << '\n';
	else cout << "1 " << r_num << '\n';

	return 0;
}