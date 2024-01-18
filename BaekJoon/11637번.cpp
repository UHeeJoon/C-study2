#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		int _max = -1, count = 1, person = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			if (_max < num) {
				_max = num;
				count = 1;
				person = i + 1;
			}
			else if (_max == num) {
				count++;
			}
			sum += num;
		}
		sum /= 2;
		if (count > 1) {
			cout << "no winner\n";
		}
		else {
			cout << (_max > sum ? "majority winner " : "minority winner ") << person << '\n';
		}

	}
	return 0;
}