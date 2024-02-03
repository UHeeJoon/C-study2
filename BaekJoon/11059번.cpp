#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int arr[1010] = { 0, };
	string str; cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		arr[i + 1] = arr[i] + (str[i] - '0');
	}
	int dist = len + ((len & 1) == 1 ? -1 : 0);
	for (int i = 0; i < dist; i += 2) {
		bool flag = false;
		int new_dist = dist - i;
		for (int j = 0; j <= len - new_dist; j++) {
			int half = j + new_dist / 2;
			int left = arr[half] - arr[j];
			int right = arr[new_dist + j] - arr[half];
			if (left == right) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << new_dist << '\n';
			break;
		}
	}
	return 0;
}