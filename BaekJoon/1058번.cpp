#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 51;
int N;
int friendsList[MAX][MAX];
void floyd(void) {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j || j == k || i == k)
					continue;
				else if (friendsList[i][j] > friendsList[i][k] + friendsList[k][j])
					friendsList[i][j] = friendsList[i][k] + friendsList[k][j];
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (i == j) friendsList[i][j] = 0;
			else
				friendsList[i][j] = s[j] == 'Y' ? 1 : INF;
		}
	}
	floyd();
	int result = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)  continue;
			else if (friendsList[i][j] <= 2)
				cnt++;
		}
		result = max(result, cnt);
	}
	cout << result << '\n';
	return 0;
}