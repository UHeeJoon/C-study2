/*
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		v[i + 1][0] += min(v[i][1], v[i][2]);
		v[i + 1][1] += min(v[i][0], v[i][2]);
		v[i + 1][2] += min(v[i][1], v[i][0]);
	}
	int min_num = min(v[n - 1][0], min(v[n - 1][1], v[n - 1][2]));
	cout << min_num << "\n";
}
*/
#include<bits/stdc++.h>
using namespace std;
int arr[1001][4], n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n - 1; i++) {
		arr[i + 1][0] += min(arr[i][1], arr[i][2]);
		arr[i + 1][1] += min(arr[i][0], arr[i][2]);
		arr[i + 1][2] += min(arr[i][1], arr[i][0]);
	}
	int min_num = min(arr[n - 1][0], min(arr[n - 1][1], arr[n - 1][2]));
	cout << min_num << "\n";
}