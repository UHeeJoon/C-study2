#include<bits/stdc++.h>
using namespace std;
#define MAX 110
#define INF 2147483647
bool student[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> student[i];
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int sex, start; cin >> sex >> start;
		if (sex == 1) {
			for (int i = 1; start * i <= n; i++)
				student[start * i] = !student[start * i];
		}
		else if (sex == 2) {
			student[start] = !student[start];
			int right = start + 1, left = start - 1;
			while (right <= n && left >= 1) {
				if (student[right] != student[left])break;
				student[right] = !student[right];
				student[left] = !student[left];
				right++;
				left--;
			}

		}
	}
	for (int i = 1; i <= n; i++) {
		cout << student[i] << ' ';
		if (i % 20 == 0) cout << '\n';
	}
	cout << '\n';
	return 0;
}