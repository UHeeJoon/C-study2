// Æ²¸²


#include<bits/stdc++.h>
using namespace std;
map<int, int> _map;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			if (_map.find(b) != _map.end()) {  
				if (_map[b] < a)
					_map[b] = a;
			}
			else { 
				_map.insert({ b,a });
			}
		}
		bool flag = false;
		int sum = 0, j = 1;
		for (auto i = _map.begin(); i != _map.end();i++) {
			if (i->first == j) {
				sum += i->second;
				j++;
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "MOREPROBLEMS\n";
		else
			cout << sum << '\n';
	}
	return 0;
}