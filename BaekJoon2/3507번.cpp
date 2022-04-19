#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	if(n >198)
		cout << 0 <<'\n';
	else {
		cout << 198 - n + 1 << '\n';
	}
	return 0;
}